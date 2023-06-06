#include "testmainwindow.h"
#include "mainwindow.h"
#include "ui/ui_mainwindow.h"

void TestMainWindow::testLightModePalette() {
    MainWindow mainWindow;
    mainWindow.lightMode();
    QPalette palette = qApp->palette();
    QCOMPARE(palette.color(QPalette::Window), QColor(228, 227, 217));
    QCOMPARE(palette.color(QPalette::WindowText), QColor(Qt::black));
}

void TestMainWindow::testConnectionPolandWidgets() {
    MainWindow mainWindow;
    mainWindow.connectionPoland();
    QCOMPARE(mainWindow.ui->lbCountryMessage->isVisible(), false);
    QCOMPARE(mainWindow.buttonCountryClicked, true);
}

void TestMainWindow::testConnectionNetherlandsWidgets() {
    MainWindow mainWindow;
    mainWindow.connectionNetherlands();
    QCOMPARE(mainWindow.ui->lbCountryMessage->isVisible(), false);
    QCOMPARE(mainWindow.buttonCountryClicked, true);
}

void TestMainWindow::testDarkModePalette() {
    MainWindow mainWindow;
    mainWindow.darkMode();
    QPalette palette = qApp->palette();
    QCOMPARE(palette.color(QPalette::Window), QColor(65, 71, 84));
    QCOMPARE(palette.color(QPalette::WindowText), QColor(Qt::white));
}

void TestMainWindow::testShowConfigurationWindow() {
    MainWindow mainWindow;
    mainWindow.showConfiguration();
    ConfigurationWindow *configWindow = qobject_cast<ConfigurationWindow *>(mainWindow.configurationWindow);
    QVERIFY(configWindow != nullptr);
}

void TestMainWindow::testShowConfigurationWindowConfigAdded() {
    MainWindow mainWindow;
    mainWindow.showConfiguration();
    ConfigurationWindow *configWindow = qobject_cast<ConfigurationWindow *>(mainWindow.configurationWindow);
    emit configWindow->valueChangedConfigAdded(true);
    QCOMPARE(mainWindow.configAdded, true);
}

