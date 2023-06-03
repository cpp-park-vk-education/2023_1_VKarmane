#include "configurationwindow.h"
#include "ui_configurationwindow.h"

#include <QTextStream>
#include <QFile>
#include <QSettings>

ConfigurationWindow::ConfigurationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationWindow) {
    ui->setupUi(this);

    // Задаем размер окна
    setFixedSize(420, 549);

    // Загружаем данные при запуске окна
    loadData();

    // Отображаем тему
    showTheme();

    // Связываем методы и сигналы
    connectSignals();
}

ConfigurationWindow::~ConfigurationWindow() {
    delete ui;
}

// Метод закрывает текущее окно и подает сигнал открытия главного окна
void ConfigurationWindow::btnBack() {
    this->close();
    emit backMainWindow();
}

// Метод сохраняет в файл обработанный список URL, полученный от пользователя
void ConfigurationWindow::saveConfig(const QString& configURLS) {
    QString filePath = "configuration.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        file.resize(0);
        QTextStream out(&file);
        out << "URLlist = " << configURLS;
        file.close();
    }
}

// Метод сохраняет и обрабатывает данные, введенные пользователем
void ConfigurationWindow::btnSave() {
    QString configURLS = ui->pteConfiguration->toPlainText();
    configURLS = configURLS.replace("\n", ",");

    // Сохраняем в файл обработанный список URL, полученный от пользователя
    saveConfig(configURLS);

    // Сохраняем данные, введенные пользователем в окно конфигурации
    saveData();

    emit valueChangedConfigAdded(true);
}

// Метод сохраняет данные, введенные пользователем в окно конфигурации для дальнейшего отображения при следующем открытии
void ConfigurationWindow::saveData() {
    // Создаем объект QSettings с указанием пути к файлу
    QSettings settings("myapp.ini", QSettings::IniFormat);

    // Сохраняем данные из QPlainTextEdit в файл
    settings.setValue("text", ui->pteConfiguration->toPlainText());
}

// Метод загружает данные, введенные пользователем в окно конфигурации при предыдущем открытии окна
void ConfigurationWindow::loadData() {
    // Создаем объект QSettings с указанием пути к файлу
    QSettings settings("myapp.ini", QSettings::IniFormat);

    // Загружаем данные из файла
    ui->pteConfiguration->setPlainText(settings.value("text").toString());
}

// Метод отображает нужную тему
void ConfigurationWindow::showTheme() {
    if (qApp->palette().windowText().color() == Qt::black) {
        ui->lightTheme->setVisible(true);
        ui->darkTheme->setVisible(false);
    } else {
        ui->lightTheme->setVisible(false);
        ui->darkTheme->setVisible(true);
    }
}

// Метод связывает методы и сигналы
void ConfigurationWindow::connectSignals() {
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(btnBack()));
    connect(ui->btnSave,SIGNAL(clicked(bool)),this, SLOT(btnSave()));
}
