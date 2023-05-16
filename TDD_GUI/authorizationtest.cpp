#include <QTest>
#include <QLineEdit>
#include "authorizationtest.h"
#include "authorization.h"


AuthorizationTest::AuthorizationTest(QObject *parent) :
    QObject(parent)
{
}

void AuthorizationTest::testAddUser() {
    QLineEdit usernameLineEdit;
    QLineEdit passwordLineEdit;
    usernameLineEdit.setText("user1");
    passwordLineEdit.setText("password1");
    Authorization users;
    users.addUser(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString());
    QVERIFY(users.userExists("user1"));
}

void AuthorizationTest::testRemoveUser() {
    QLineEdit usernameLineEdit;
    QLineEdit passwordLineEdit;
    usernameLineEdit.setText("user2");
    passwordLineEdit.setText("password2");
    Authorization users;
    users.addUser(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString());
    users.removeUser(usernameLineEdit.text().toStdString());
    QVERIFY(!users.userExists("user2"));
}

void AuthorizationTest::testUserExists() {
    QLineEdit usernameLineEdit;
    QLineEdit passwordLineEdit;
    usernameLineEdit.setText("user3");
    passwordLineEdit.setText("password3");
    Authorization users;
    users.addUser(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString());
    QVERIFY(users.userExists("user3"));
    QVERIFY(!users.userExists("user4"));
}

void AuthorizationTest::testCheckPassword() {
    QLineEdit usernameLineEdit;
    QLineEdit passwordLineEdit;
    usernameLineEdit.setText("user5");
    passwordLineEdit.setText("password5");
    Authorization users;
    users.addUser(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString());
    QVERIFY(users.checkPassword(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString()));
    passwordLineEdit.setText("password6");
    QVERIFY(!users.checkPassword(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString()));
}

void AuthorizationTest::testClearCredentials() {
    QLineEdit usernameLineEdit;
    QLineEdit passwordLineEdit;
    usernameLineEdit.setText("user6");
    passwordLineEdit.setText("password6");
    Authorization users;
    users.addUser(usernameLineEdit.text().toStdString(), passwordLineEdit.text().toStdString());
    users.clearCredentials();
    QVERIFY(!users.userExists("user6"));
}
