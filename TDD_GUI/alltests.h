#ifndef ALLTESTS_H
#define ALLTESTS_H

#include <QtTest>

class AllTests : public QObject
{
    Q_OBJECT
public:
    explicit AllTests(QObject *parent = 0);

private slots:
    void runAllTests();
};

#endif // ALLTESTS_H
