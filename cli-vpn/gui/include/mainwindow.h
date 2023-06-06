#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "staticswindow.h"
//#include "authenticationwindow.h"
#include "configurationwindow.h"
#include "countries.h"

#include "VPNClient.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void lightMode();
    void darkMode();

    void connectionPoland();
    void connectionNetherlands();

//    void showStatics();
//    void showAuthorization();
    void showConfiguration();
    void showCountries();

    void turnVPN();
    void turnOffVPN(VPNClient& client);
    void turnOnVPN(VPNClient& client);

    void setValueButtonCountryClicked(bool value);
    void setValueDefaultConfiguration(const std::string& value);
    void setValueConfigAdded(bool value);
    void setValueNameTun(const std::string& value);

    void clearConfig(const QString& filePath);

    void connectLogo();
    void connectSignals();

private:
    Ui::MainWindow *ui;
    Countries* countriesWindow;
    ConfigurationWindow* configurationWindow;

//    StaticsWindow statics;
//    AuthenticationWindow authentication;

    bool buttonClicked;
    bool buttonCountryClicked;
    bool configAdded;

    std::string nameTun;
    std::string defaultConfiguration;

    QString filePath;

};
#endif // MAINWINDOW_H
