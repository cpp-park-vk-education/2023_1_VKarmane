#ifndef URLCONFIGURATION_H
#define URLCONFIGURATION_H

#include <QObject>

class URLConfiguration : public QObject
{
    Q_OBJECT
public:
    explicit URLConfiguration(QObject *parent = 0);

public slots:
    void getURLFromUser(const std::string& URL);

    std::vector<std::string>& getURLList();

    void clearURLList();

    void removeURL(const std::string& URL);

private:
    std::vector<std::string> URLList;
};

#endif // URLCONFIGURATION_H
