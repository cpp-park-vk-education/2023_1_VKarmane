#include "testconfigurationwindow.h"
#include "configurationwindow.h"
#include "ui/ui_configurationwindow.h"


void TestConfigurationWindow::testSaveConfig() {
    ConfigurationWindow window;
    QString configURLS = "https://example.com,https://example.org";
    window.saveConfig(configURLS);

    QFile file("configuration.txt");
    QVERIFY(file.exists());

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();
        QCOMPARE(line, QString("URLlist = https://example.com,https://example.org"));
        file.close();
    } else {
        QFAIL("Failed to open file");
    }
}


void TestConfigurationWindow::testBtnSave() {
    ConfigurationWindow window;
    window.ui->pteConfiguration->setPlainText("https://example.com\nhttps://example.org\n");
    window.btnSave();

    QSettings settings("myapp.ini", QSettings::IniFormat);
    QString text = settings.value("text").toString();
    QCOMPARE(text, QString("https://example.com\nhttps://example.org\n"));
}


void TestConfigurationWindow::testSaveData() {
    ConfigurationWindow window;
    window.ui->pteConfiguration->setPlainText("https://example.com\nhttps://example.org\n");
    window.saveData();

    QSettings settings("myapp.ini", QSettings::IniFormat);
    QString text = settings.value("text").toString();
    QCOMPARE(text, QString("https://example.com\nhttps://example.org\n"));
}


void TestConfigurationWindow::testLoadData() {
    ConfigurationWindow window;
    QSettings settings("myapp.ini", QSettings::IniFormat);
    settings.setValue("text", "https://example.com\nhttps://example.org\n");
    window.loadData();

    QString text = window.ui->pteConfiguration->toPlainText();
    QCOMPARE(text, QString("https://example.com\nhttps://example.org\n"));
}




