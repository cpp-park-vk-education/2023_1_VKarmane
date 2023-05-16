#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>

class Authorization : public QObject
{
    Q_OBJECT
public:
    explicit Authorization(QObject *parent = 0);

public slots:
    void addUser(const std::string& username, const std::string& password);
    void removeUser(const std::string& username);
    bool userExists(const std::string& username);
    bool checkPassword(const std::string& username, const std::string& password);
    void clearCredentials();

private:
    std::unordered_map<std::string, std::string> userCredentials;
};

#endif // AUTHORIZATION_H
