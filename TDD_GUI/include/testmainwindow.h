#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H


#include <QtTest/QtTest>

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    void testLightModePalette();
    void testConnectionPolandWidgets();
    void testConnectionNetherlandsWidgets();
    void testDarkModePalette();
    void testShowConfigurationWindow();
    void testShowConfigurationWindowConfigAdded();
};

#endif // TESTMAINWINDOW_H
