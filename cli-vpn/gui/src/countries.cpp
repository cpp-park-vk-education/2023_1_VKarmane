#include "countries.h"
#include "ui_countries.h"

Countries::Countries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Countries)
{
    ui->setupUi(this);
    setFixedSize(420, 549);

    if (qApp->palette().windowText().color() == Qt::black) {
        ui->lightTheme->setVisible(true);
        ui->darkTheme->setVisible(false);
    } else {
        ui->lightTheme->setVisible(false);
        ui->darkTheme->setVisible(true);
    }

    ui->lwServers->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lbFieldsCheck->setVisible(false);

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(btnBack()));

    connect(ui->btnAdd, SIGNAL(clicked(bool)), this, SLOT(readLEServerIP()));

    connect(ui->btnDelete, SIGNAL(clicked(bool)), this, SLOT(deleteServerIP()));

    connect(ui->btnChoose, SIGNAL(clicked(bool)), this, SLOT(chooseServerIP()));
}

Countries::~Countries() {
    delete ui;
}

void Countries::btnBack() {
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

    std::string ServerName = "\n" + selectedServerName.toStdString() + " = ";
    std::string ServerIP = selectedServerIP.toStdString();

    emit valueChangedButtonCountryClicked(true);
    emit valueChangedNameTun(ServerName);
    emit valueChangedDefaultConfiguration(ServerIP);
}

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
    ui->lwServers->setColumnCount(2);

    ui->lwServers->horizontalHeader()->setStretchLastSection(true); // отключаем растягивание последнего столбца по умолчанию

    QTableWidgetItem* itemIP = new QTableWidgetItem(serverIP); // создаем элемент для первого столбца
    QTableWidgetItem* itemName = new QTableWidgetItem(serverName); // создаем элемент для второго столбца

    ui->lwServers->setSelectionBehavior(QAbstractItemView::SelectRows); // устанавливаем поведение выбора на выбор всей строки

    ui->lwServers->setItem(row, 0, itemIP); // добавляем элемент в первый столбец новой строки
    ui->lwServers->setItem(row, 1, itemName); // добавляем элемент во второй столбец новой строки
}
