#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "staticswindow.h"
#include "authenticationwindow.h"
#include "configurationwindow.h"
#include "countries.h"

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

    void showStatics();
    void showAuthorization();
    void showConfiguration();

    void turnOnVPN();
    void showCountries();

    void setValueButtonCountryClicked(bool value);
    void setValueDefaultConfiguration(std::string value);
    void setValueConfigAdded(bool value);


private:
    Ui::MainWindow *ui;
    Countries* countriesWindow;
    ConfigurationWindow* configurationWindow;

    StaticsWindow statics;
    AuthenticationWindow authentication;
    ConfigurationWindow configuration;

    bool buttonClicked;
    bool buttonCountryClicked;
    bool configAdded;

    std::string defaultConfiguration;

};
#endif // MAINWINDOW_H
