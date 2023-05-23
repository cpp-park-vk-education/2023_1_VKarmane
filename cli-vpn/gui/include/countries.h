#ifndef COUNTRIES_H
#define COUNTRIES_H

#include <QDialog>

namespace Ui {
class Countries;
}

class Countries : public QDialog
{
    Q_OBJECT

 public:
    explicit Countries(QWidget *parent = nullptr);
    ~Countries();

 private:
    Ui::Countries *ui;

    bool buttonCountryClicked;
    std::string defaultConfiguration;

 signals:
    void valueChangedNameTun(std::string value);
    void backMainWindow();
    void valueChangedButtonCountryClicked(bool value);
    void valueChangedDefaultConfiguration(std::string value);


 private slots:
    void back();
    void readLEServerIP();
    void deleteServerIP();
    void chooseServerIP();
};

#endif // COUNTRIES_H
