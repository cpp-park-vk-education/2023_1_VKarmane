#include "authorization.h"


Authorization::Authorization(QObject *parent) :
    QObject(parent)
{
}

void Authorization::addUser(const std::string& username, const std::string& password) {
}

void Authorization::removeUser(const std::string& username) {
}

bool Authorization::userExists(const std::string& username) {
    return false;
}

bool Authorization::checkPassword(const std::string& username, const std::string& password) {
    return false;
}

void Authorization::clearCredentials() {
}
