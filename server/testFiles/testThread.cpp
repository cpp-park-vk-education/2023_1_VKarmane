#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

using boost::asio::ip::tcp;

// Структура для хранения данных клиента
struct client_data {
  std::string ip_address;
  std::string public_key;
};

int main() {
  // Создаем объект io_service
  boost::asio::io_service io_service;

  // Создаем объект acceptor и привязываем его к локальному порту 5555
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 5555));

  // Создаем контейнер для хранения данных клиентов
  std::unordered_map<std::string, client_data> client_map;

  // Функция обработки соединений
  auto handle_connection = [&](tcp::socket socket) {
    try {
      // Получаем IP-адрес клиента
      std::string client_ip_address = socket.remote_endpoint().address().to_string();

      // Создаем буфер для чтения данных от клиента
      boost::asio::streambuf buffer;
      boost::asio::read_until(socket, buffer, '\n');

      // Читаем данные из буфера
      std::string public_key(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()) - 1);

      // Добавляем клиента в конфиг
      client_map[client_ip_address] = {client_ip_address, public_key};

      // Отправляем клиенту IP-адрес сервера и его public key
      std::string server_ip_address = socket.local_endpoint().address().to_string();
      std::string message = "IP: " + server_ip_address + "\nPublic key: " + public_key + "\n";
      boost::asio::write(socket, boost::asio::buffer(message));

      // Закрываем соединение
      socket.shutdown(tcp::socket::shutdown_both);
      socket.close();
    } catch (std::exception& e) {
      std::cerr << "Exception in thread: " << e.what() << "\n";
    }
  };

  // Функция для запуска сервера
  auto run_server = [&]() {
    while (true) {
      // Создаем сокет для соединения с клиентом
      tcp::socket socket(io_service);

      // Принимаем соединение от клиента
      acceptor.accept(socket);

      // Запускаем функцию обработки соединения в новом потоке
      std::thread(handle_connection, std::move(socket)).detach();
    }
  };

  // Запускаем сервер
  run_server();

  return 0;
}
