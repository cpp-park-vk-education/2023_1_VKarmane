#ifndef AUTHORIZATIONTEST_H
#define AUTHORIZATIONTEST_H

#include <QtTest>

class AuthorizationTest : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationTest(QObject *parent = 0);

private slots:
    void testAddUser();
    void testRemoveUser();
    void testUserExists();
    void testCheckPassword();
    void testClearCredentials();
};

#endif // AUTHORIZATIONTEST_H
