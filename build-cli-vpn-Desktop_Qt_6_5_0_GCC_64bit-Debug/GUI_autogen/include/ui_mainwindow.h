/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *DarkMode;
    QAction *LightMode;
    QAction *showStatistics;
    QAction *showConfiguration;
    QAction *showAuthorization;
    QAction *connectInstagramm;
    QAction *connectTwitter;
    QAction *connectPoland;
    QAction *connectChina;
    QAction *connectSweden;
    QAction *connectNetherlands;
    QAction *actionNewCountry;
    QWidget *centralwidget;
    QPushButton *btnTurnVpn;
    QLabel *lbFoxTail;
    QLabel *lbCountryMessage;
    QLabel *lbConfigUsageOff;
    QLabel *lbConfigUsageOn;
    QMenuBar *menubar;
    QMenu *menuChoose_theme;
    QMenu *menuSettings;
    QStatusBar *statusbar;
    QToolBar *tbSites;
    QToolBar *tbCountries;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(420, 476);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        DarkMode = new QAction(MainWindow);
        DarkMode->setObjectName("DarkMode");
        LightMode = new QAction(MainWindow);
        LightMode->setObjectName("LightMode");
        showStatistics = new QAction(MainWindow);
        showStatistics->setObjectName("showStatistics");
        showConfiguration = new QAction(MainWindow);
        showConfiguration->setObjectName("showConfiguration");
        showAuthorization = new QAction(MainWindow);
        showAuthorization->setObjectName("showAuthorization");
        connectInstagramm = new QAction(MainWindow);
        connectInstagramm->setObjectName("connectInstagramm");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/1491579602-yumminkysocialmedia36_83067.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectInstagramm->setIcon(icon);
        connectTwitter = new QAction(MainWindow);
        connectTwitter->setObjectName("connectTwitter");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Twitter_icon-icons.com_66803.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectTwitter->setIcon(icon1);
        connectPoland = new QAction(MainWindow);
        connectPoland->setObjectName("connectPoland");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/flagofpoland_6425.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectPoland->setIcon(icon2);
        connectChina = new QAction(MainWindow);
        connectChina->setObjectName("connectChina");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/FlagChineseFlag_banderadechina_6561.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectChina->setIcon(icon3);
        connectSweden = new QAction(MainWindow);
        connectSweden->setObjectName("connectSweden");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/swedenflag_6382.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectSweden->setIcon(icon4);
        connectNetherlands = new QAction(MainWindow);
        connectNetherlands->setObjectName("connectNetherlands");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Dutchflag_6447.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectNetherlands->setIcon(icon5);
        actionNewCountry = new QAction(MainWindow);
        actionNewCountry->setObjectName("actionNewCountry");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/add_circle_create_expand_new_plus_icon_123218.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewCountry->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnTurnVpn = new QPushButton(centralwidget);
        btnTurnVpn->setObjectName("btnTurnVpn");
        btnTurnVpn->setEnabled(true);
        btnTurnVpn->setGeometry(QRect(150, 250, 121, 111));
        btnTurnVpn->setCursor(QCursor(Qt::PointingHandCursor));
        btnTurnVpn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-image:url(:/img/arrows-button-off_98344.png);\n"
"width: 50px;\n"
"height: 50px;\n"
"}\n"
"QPushButton:checked{\n"
"width: 50px;\n"
"height: 50px;\n"
"border-image:url(:/img/arrows-button-on_97730.png);\n"
"}"));
        btnTurnVpn->setIconSize(QSize(200, 100));
        btnTurnVpn->setCheckable(true);
        btnTurnVpn->setFlat(true);
        lbFoxTail = new QLabel(centralwidget);
        lbFoxTail->setObjectName("lbFoxTail");
        lbFoxTail->setGeometry(QRect(150, 110, 121, 121));
        lbFoxTail->setPixmap(QPixmap(QString::fromUtf8(":/img/FoxTailVPNLogo.png")));
        lbFoxTail->setScaledContents(true);
        lbCountryMessage = new QLabel(centralwidget);
        lbCountryMessage->setObjectName("lbCountryMessage");
        lbCountryMessage->setEnabled(true);
        lbCountryMessage->setGeometry(QRect(140, 140, 161, 51));
        lbConfigUsageOff = new QLabel(centralwidget);
        lbConfigUsageOff->setObjectName("lbConfigUsageOff");
        lbConfigUsageOff->setEnabled(true);
        lbConfigUsageOff->setGeometry(QRect(300, 0, 121, 21));
        lbConfigUsageOn = new QLabel(centralwidget);
        lbConfigUsageOn->setObjectName("lbConfigUsageOn");
        lbConfigUsageOn->setEnabled(true);
        lbConfigUsageOn->setGeometry(QRect(300, 0, 101, 21));
        MainWindow->setCentralWidget(centralwidget);
        lbFoxTail->raise();
        btnTurnVpn->raise();
        lbCountryMessage->raise();
        lbConfigUsageOff->raise();
        lbConfigUsageOn->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 22));
        menuChoose_theme = new QMenu(menubar);
        menuChoose_theme->setObjectName("menuChoose_theme");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        tbSites = new QToolBar(MainWindow);
        tbSites->setObjectName("tbSites");
        tbSites->setMinimumSize(QSize(200, 40));
        tbSites->setMaximumSize(QSize(200, 40));
        tbSites->setMovable(false);
        MainWindow->addToolBar(Qt::BottomToolBarArea, tbSites);
        tbCountries = new QToolBar(MainWindow);
        tbCountries->setObjectName("tbCountries");
        tbCountries->setMinimumSize(QSize(220, 40));
        tbCountries->setMaximumSize(QSize(220, 40));
        tbCountries->setMovable(false);
        MainWindow->addToolBar(Qt::BottomToolBarArea, tbCountries);

        menubar->addAction(menuChoose_theme->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuChoose_theme->addAction(DarkMode);
        menuChoose_theme->addAction(LightMode);
        menuSettings->addAction(showConfiguration);
        tbSites->addAction(connectInstagramm);
        tbSites->addAction(connectTwitter);
        tbCountries->addAction(connectNetherlands);
        tbCountries->addAction(connectPoland);
        tbCountries->addAction(actionNewCountry);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Foxtail VPN", nullptr));
        DarkMode->setText(QCoreApplication::translate("MainWindow", "Dark mode", nullptr));
        LightMode->setText(QCoreApplication::translate("MainWindow", "Light mode", nullptr));
        showStatistics->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        showConfiguration->setText(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        showAuthorization->setText(QCoreApplication::translate("MainWindow", "Authorization", nullptr));
        connectInstagramm->setText(QCoreApplication::translate("MainWindow", "Insta", nullptr));
        connectTwitter->setText(QCoreApplication::translate("MainWindow", "twitter", nullptr));
        connectPoland->setText(QCoreApplication::translate("MainWindow", "poland", nullptr));
        connectChina->setText(QCoreApplication::translate("MainWindow", "china", nullptr));
        connectSweden->setText(QCoreApplication::translate("MainWindow", "swedish", nullptr));
        connectNetherlands->setText(QCoreApplication::translate("MainWindow", "Netherlands", nullptr));
        actionNewCountry->setText(QCoreApplication::translate("MainWindow", "newCountry", nullptr));
        btnTurnVpn->setText(QString());
        lbFoxTail->setText(QString());
        lbCountryMessage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><a name=\"tw-target-text\"/><span style=\" font-family:'inherit'; color:#a51d2d;\">C</span><span style=\" font-family:'inherit'; color:#a51d2d;\">hoose country or </span></p><p><span style=\" font-family:'inherit'; color:#a51d2d;\">set up your server IP</span></p></body></html>", nullptr));
        lbConfigUsageOff->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#a51d2d;\">Config isn't active</span></p></body></html>", nullptr));
        lbConfigUsageOn->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#26a269;\">Config is active</span></p></body></html>", nullptr));
        menuChoose_theme->setTitle(QCoreApplication::translate("MainWindow", "Choose theme", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        tbSites->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        tbCountries->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
