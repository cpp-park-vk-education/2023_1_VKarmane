#include "configurationwindow.h"
#include "ui_configurationwindow.h"

#include <QTextStream>
#include <QFile>
#include <QSettings>

ConfigurationWindow::ConfigurationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationWindow) {
    ui->setupUi(this);
    setFixedSize(420, 549);

    // Загружаем данные при запуске окна
    loadData();

    if (qApp->palette().windowText().color() == Qt::black) {
        ui->lightTheme->setVisible(true);
        ui->darkTheme->setVisible(false);
    } else {
        ui->lightTheme->setVisible(false);
        ui->darkTheme->setVisible(true);
    }


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

void ConfigurationWindow::btnSave() {
    QString configURLS = ui->pteConfiguration->toPlainText();
    configURLS = configURLS.replace("\n", ",");
    saveConfig(configURLS);
    // Сохраняем данные после нажатия кнопки "Сохранить"
    saveData();
    emit valueChangedConfigAdded(true);
}


void ConfigurationWindow::saveData() {
    // Создаем объект QSettings с указанием пути к файлу
    QSettings settings("myapp.ini", QSettings::IniFormat);

    // Сохраняем данные из QPlainTextEdit в файл
    settings.setValue("text", ui->pteConfiguration->toPlainText());
}

void ConfigurationWindow::loadData() {
    // Создаем объект QSettings с указанием пути к файлу
    QSettings settings("myapp.ini", QSettings::IniFormat);

    // Загружаем данные из файла
    ui->pteConfiguration->setPlainText(settings.value("text").toString());
}
