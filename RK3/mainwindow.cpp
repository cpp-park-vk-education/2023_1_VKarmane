#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDir>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , requestNumber(0)
{
    QString filePath = "/home/scremyda/QT projects/RK2/conf/configuration.txt";
    QDir::setCurrent(QFileInfo(filePath).absolutePath());
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        file.resize(0);
        file.close();
    }

    buttonClicked = false;

    buttonCountryClicked = false;

    darkMode();

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    ui->setupUi(this);
    ui->lbFoxTail->setVisible(false);

    connect(ui->LightMode, &QAction::triggered, this, &MainWindow::lightMode);
    connect(ui->DarkMode, &QAction::triggered, this, &MainWindow::darkMode);

    connect(ui->btnTurnVpn,SIGNAL(clicked(bool)),this, SLOT(turnOnVPN()));

    connect(ui->showStatistics, &QAction::triggered, this, &MainWindow::showStatics);
    connect(ui->showAuthorization, &QAction::triggered, this, &MainWindow::showAuthorization);
    connect(ui->showConfiguration, &QAction::triggered, this, &MainWindow::showConfiguration);

    connect(ui->connectPoland, &QAction::triggered, this, &MainWindow::connectionPoland);
    connect(ui->connectNetherlands, &QAction::triggered, this, &MainWindow::connectionNetherlands);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::turnOnVPN() {
    if (buttonCountryClicked) {
        ui->lbCountryMessage->setVisible(false);
        if (!buttonClicked) {
            ui->btnTurnVpn->setStyleSheet("QPushButton {border-image:url(:/img/arrows-button-on_97730.png); width: 50px; height: 50px;}");
            ui->lbFoxTail->setVisible(true);
            buttonClicked = true;

            if (defaultConfiguration[1] == "") {
                defaultConfiguration[1] = "0.0.0.0";
            }

            QString filePath = "/home/scremyda/QT projects/RK2/conf/configuration.txt";
            QDir::setCurrent(QFileInfo(filePath).absolutePath());
            QFile file(filePath);
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream stream(&file);
                std::cout << "Данные записываются";
                stream << QString::fromStdString(defaultConfiguration[0]) << ", " << QString::fromStdString(defaultConfiguration[1]) << "\n";
                if (stream.status() != QTextStream::Ok) {
                    std::cout << "Error writing to file";
                }
                file.close();
            } else {
                std::cout << "Error opening file";
            }


        } else {
            ui->btnTurnVpn->setStyleSheet("QPushButton {border-image:url(:/img/arrows-button-off_98344.png); width: 50px; height: 50px;}");
            ui->lbFoxTail->setVisible(false);
            buttonClicked = false;
            buttonCountryClicked = false;
        }
    } else {
        ui->lbCountryMessage->setVisible(true);
        ui->btnTurnVpn->setStyleSheet("QPushButton {border-image:url(:/img/arrows-button-off_98344.png); width: 50px; height: 50px;}");
    }

}


void MainWindow::lightMode() {
    QPalette lightPalette;

    // Настраиваем палитру для цветовых ролей элементов интерфейса
    lightPalette.setColor(QPalette::Window, Qt::white);
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, Qt::lightGray);
    lightPalette.setColor(QPalette::AlternateBase, Qt::white);
    lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, Qt::lightGray);
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::BrightText, Qt::red);
    lightPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    lightPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);

    // Устанавливаем данную палитру
    qApp->setPalette(lightPalette);

}

void MainWindow::connectionPoland() {
    if (requestNumber == defaultConfiguration.size()) {
        defaultConfiguration.resize(1 + requestNumber * 2);
    }
    defaultConfiguration.clear();
    defaultConfiguration.resize(2);
    defaultConfiguration[0] = "URLlist = 104.18.2.161/32, 104.18.3.161/32, 195.201.201.32";
    buttonCountryClicked = true;
}

void MainWindow::connectionNetherlands() {
    if (requestNumber == defaultConfiguration.size()) {
        defaultConfiguration.resize(1 + requestNumber * 2);
    }
    defaultConfiguration.clear();
    defaultConfiguration.resize(2);
    defaultConfiguration[0] = "URLlist = 104.18.2.161/32, 104.18.3.161/32, 195.201.201.32";
    buttonCountryClicked = true;
}


void MainWindow::darkMode() {
    QPalette darkPalette;

    // Настраиваем палитру для цветовых ролей элементов интерфейса
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    // Устанавливаем данную палитру
    qApp->setPalette(darkPalette);

}


void MainWindow::showStatics() {
    statics.show();
}


void MainWindow::showAuthorization() {
    authentication.show();
}


void MainWindow::showConfiguration() {
    configuration.show();
}

