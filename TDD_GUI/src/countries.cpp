#include "countries.h"
#include "ui/ui_countries.h"

#include <QSettings>

Countries::Countries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Countries)
{
    ui->setupUi(this);

    setFixedSize(420, 549);

    showTheme();

    ui->lwServers->setEditTriggers(QAbstractItemView::NoEditTriggers);

    loadTableData();

    ui->lbFieldsCheck->setVisible(false);

    connectSignals();
}

Countries::~Countries() {
    delete ui;
}

void Countries::setUi(Ui::Countries* ui) {
    this->ui = ui;
}

Ui::Countries* Countries::getUi() {
    return ui;
}



void Countries::btnBack() {
    saveTableData();
    this->close();
    emit backMainWindow();
}

void Countries::deleteServerIP() {
    ui->lwServers->removeRow(ui->lwServers->currentRow());
}

void Countries::chooseServerIP() {
    if (ui->lwServers->currentRow() == -1) {
        return;
    }
    QString selectedServerName = ui->lwServers->item(ui->lwServers->currentRow(), 0)->text();
    QString selectedServerIP = ui->lwServers->item(ui->lwServers->currentRow(), 1)->text();

    std::string ServerName = selectedServerName.toStdString();
    std::string ServerIP = "\nEndpoint = " + selectedServerIP.toStdString();

    emit valueChangedButtonCountryClicked(true);
    emit valueChangedNameTun(ServerName);
    emit valueChangedDefaultConfiguration(ServerIP);
}

// Метод считывает введенные пользователем данные о сервере
void Countries::readLEServerIP() {
    if (ui->leServers->text().isEmpty() or ui->leServersName->text().isEmpty()) {
        ui->lbFieldsCheck->setVisible(true);
        return;
    } else {
        ui->lbFieldsCheck->setVisible(false);
    }
    QString serverIP = ui->leServers->text();
    QString serverName = ui->leServersName->text();

    int row = ui->lwServers->rowCount();
    ui->lwServers->insertRow(row);

    ui->lwServers->horizontalHeader()->setStretchLastSection(true); // отключаем растягивание последнего столбца по умолчанию

    QTableWidgetItem* itemIP = new QTableWidgetItem(serverIP); // создаем элемент для первого столбца
    QTableWidgetItem* itemName = new QTableWidgetItem(serverName); // создаем элемент для второго столбца

    ui->lwServers->setSelectionBehavior(QAbstractItemView::SelectRows); // устанавливаем поведение выбора на выбор всей строки

    ui->lwServers->setItem(row, 0, itemName); // добавляем элемент в первый столбец новой строки
    ui->lwServers->setItem(row, 1, itemIP); // добавляем элемент во второй столбец новой строки
}


void Countries::saveTableData() {
    QSettings settings("MyCompany", "MyApp");
    settings.beginWriteArray("servers");
    for (int i = 0; i < ui->lwServers->rowCount(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("name", ui->lwServers->item(i, 0)->text());
        settings.setValue("ip", ui->lwServers->item(i, 1)->text());
    }
    settings.endArray();
}

void Countries::loadTableData() {
    QSettings settings("MyCompany", "MyApp");
    int size = settings.beginReadArray("servers");
    ui->lwServers->setColumnCount(2);
    ui->lwServers->horizontalHeader()->setStretchLastSection(true);
    ui->lwServers->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headers;
    headers << "Название" << "IP-адрес";
    ui->lwServers->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString name = settings.value("name").toString();
        QString ip = settings.value("ip").toString();
        int row = ui->lwServers->rowCount();
        ui->lwServers->insertRow(row);
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        QTableWidgetItem* itemIP = new QTableWidgetItem(ip);
        ui->lwServers->setItem(row, 0, itemName);
        ui->lwServers->setItem(row, 1, itemIP);
    }
    settings.endArray();
}

void Countries::connectSignals() {
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(btnBack()));
    connect(ui->btnAdd, SIGNAL(clicked(bool)), this, SLOT(readLEServerIP()));
    connect(ui->btnDelete, SIGNAL(clicked(bool)), this, SLOT(deleteServerIP()));
    connect(ui->btnChoose, SIGNAL(clicked(bool)), this, SLOT(chooseServerIP()));
}

void Countries::showTheme() {
    if (qApp->palette().windowText().color() == Qt::black) {
        ui->lightTheme->setVisible(true);
        ui->darkTheme->setVisible(false);
    } else {
        ui->lightTheme->setVisible(false);
        ui->darkTheme->setVisible(true);
    }
}

