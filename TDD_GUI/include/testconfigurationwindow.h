#ifndef TESTCONFIGURATIONWINDOW_H
#define TESTCONFIGURATIONWINDOW_H

#include <QtTest/QtTest>

class TestConfigurationWindow : public QObject {
    Q_OBJECT

private slots:
    void testSaveConfig();
    void testBtnSave();
    void testSaveData();
    void testLoadData();
};

#endif // TESTCONFIGURATIONWINDOW_H
