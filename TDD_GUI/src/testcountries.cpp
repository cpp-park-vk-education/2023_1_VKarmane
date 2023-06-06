#include "testcountries.h"
#include "countries.h"
#include "ui/ui_countries.h"


#include <QListWidget>


void TestCountries::testReadLEServerIP() {
    QLineEdit* lineEditIP = new QLineEdit();
    lineEditIP->setText("");
    QLineEdit* lineEditName = new QLineEdit();
    lineEditName->setText("Server 1");
    Countries* countries = new Countries();
    countries->setUi(new Ui::Countries());
    countries->getUi()->leServers = lineEditIP;
    countries->getUi()->leServersName = lineEditName;
    QLabel* label = new QLabel();
    countries->getUi()->lbFieldsCheck = label;
    countries->readLEServerIP();
    QVERIFY(label->isVisible());
    delete countries;
    delete lineEditIP;
    delete lineEditName;
    delete label;
}

void TestCountries::testConnectSignals() {
    QPushButton* buttonBack = new QPushButton();
    QPushButton* buttonAdd = new QPushButton();
    QPushButton* buttonDelete = new QPushButton();
    QPushButton* buttonChoose = new QPushButton();
    Countries* countries = new Countries();
    countries->setUi(new Ui::Countries());
    countries->getUi()->btnBack = buttonBack;
    countries->getUi()->btnAdd = buttonAdd;
    countries->getUi()->btnDelete = buttonDelete;
    countries->getUi()->btnChoose = buttonChoose;
    countries->connectSignals();
    QVERIFY(QObject::connect(buttonBack, SIGNAL(clicked(bool)), countries, SLOT(btnBack())));
    QVERIFY(QObject::connect(buttonAdd, SIGNAL(clicked(bool)), countries, SLOT(readLEServerIP())));
    QVERIFY(QObject::connect(buttonDelete, SIGNAL(clicked(bool)), countries, SLOT(deleteServerIP())));
    QVERIFY(QObject::connect(buttonChoose, SIGNAL(clicked(bool)), countries, SLOT(chooseServerIP())));
    delete countries;
    delete buttonBack;
    delete buttonAdd;
    delete buttonDelete;
    delete buttonChoose;
}

