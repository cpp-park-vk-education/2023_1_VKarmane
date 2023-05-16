#ifndef TESTS_H
#define TESTS_H

#include <QtTest/QtTest>


class Tests : public QObject
{
    Q_OBJECT

public:
    explicit Tests(QObject* parent = 0);

private slots:
    void testSquare();
};

#endif // TESTS_H
