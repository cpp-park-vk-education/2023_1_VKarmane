#ifndef TESTCOUNTRIES_H
#define TESTCOUNTRIES_H

#include <QtTest/QtTest>

class TestCountries : public QObject
{
    Q_OBJECT

private slots:
    void testReadLEServerIP();
    void testConnectSignals();
};




#endif // TESTCOUNTRIES_H
