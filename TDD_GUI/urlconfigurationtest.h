#ifndef URLCONFIGURATIONTEST_H
#define URLCONFIGURATIONTEST_H

#include <QtTest>

class URLConfigurationTest : public QObject
{
    Q_OBJECT
public:
    explicit URLConfigurationTest(QObject *parent = 0);

private slots:
    void testGetURLList();
    void testEmptyURLList();
    void testQLineEditURL();
    void testQLineEditNotURL();
    void testAddURL();
    void testRemoveURL();
    void testClearURLList();
    void testInvalidURL();
    void testDuplicateURL();
    void testEmptyURL();
    void testURLWithSpaces();
    void testURLWithDifferentProtocols();
    void testURLWithDifferentPorts();
    void testAddNotURL();
};

#endif // URLCONFIGURATIONTEST_H
