#ifndef COUNTRIES_H
#define COUNTRIES_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class Countries;
}
QT_END_NAMESPACE

class ICountriesWindow {
    virtual void btnBack() = 0;
    virtual void readLEServerIP() = 0;
    virtual void deleteServerIP() = 0;
    virtual void chooseServerIP() = 0;
};

class Countries : public QDialog, public ICountriesWindow {
    Q_OBJECT

 public:
    explicit Countries(QWidget *parent = nullptr);
    ~Countries();

 private:
    Ui::Countries *ui;

    bool buttonCountryClicked;
    std::string defaultConfiguration;

 signals:
    void valueChangedNameTun(const std::string& value);
    void backMainWindow();
    void valueChangedButtonCountryClicked(bool value);
    void valueChangedDefaultConfiguration(const std::string& value);


 private slots:
    void btnBack() override;
    void readLEServerIP() override;
    void deleteServerIP() override;
    void chooseServerIP() override;
};

#endif // COUNTRIES_H
