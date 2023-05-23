#include "countries.h"
#include "ui_countries.h"

Countries::Countries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Countries)
{
    ui->setupUi(this);
    setFixedSize(420, 476);

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
    delete ui->lwServers->takeItem(ui->lwServers->currentRow());
}

void Countries::chooseServerIP() {
    if (ui->lwServers->currentRow() == -1) {
        return;
    }
    QListWidgetItem *currentItem = ui->lwServers->currentItem();
    QString selectedText = currentItem->text();
    std::string selectedTextStd = "\nEndpoint =" + selectedText.toStdString();
    emit valueChangedNameTun(selectedTextStd);
    emit valueChangedButtonCountryClicked(true);
    emit valueChangedDefaultConfiguration(selectedTextStd);
}

void Countries::readLEServerIP() {
    if (ui->leServers->text().isEmpty()) {
        return;
    }
    QString text = ui->leServers->text();
    std::string serverName = text.toStdString();
    ui->lwServers->addItem(QString::fromStdString(serverName));
}
