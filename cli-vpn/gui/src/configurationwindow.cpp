#include "configurationwindow.h"
#include "ui_configurationwindow.h"
#include <QTextStream>
#include <QFile>


ConfigurationWindow::ConfigurationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationWindow) {
    ui->setupUi(this);
    setFixedSize(420, 476);


    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(btnBack()));
    connect(ui->btnSave,SIGNAL(clicked(bool)),this, SLOT(btnSave()));
}

ConfigurationWindow::~ConfigurationWindow() {
    delete ui;
}

void ConfigurationWindow::btnBack() {
    this->close();
    emit backMainWindow();
}

void ConfigurationWindow::btnSave() {
    QString text = ui->pteConfiguration->toPlainText();
    text = text.replace("\n", ",");
    QString filePath = "conf/configuration.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        file.resize(0);
        QTextStream out(&file);
        out << "URLList=" << text;
        file.close();
    }
    emit valueChangedConfigAdded(true);
}

void ConfigurationWindow::btnDelete() {

}

