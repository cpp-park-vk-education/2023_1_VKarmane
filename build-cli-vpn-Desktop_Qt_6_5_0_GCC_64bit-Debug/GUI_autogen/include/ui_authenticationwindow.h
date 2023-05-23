/********************************************************************************
** Form generated from reading UI file 'authenticationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATIONWINDOW_H
#define UI_AUTHENTICATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AuthenticationWindow
{
public:
    QLineEdit *leEmail;
    QLineEdit *lePassword;
    QPushButton *pushButton;
    QPushButton *btnBack;

    void setupUi(QDialog *AuthenticationWindow)
    {
        if (AuthenticationWindow->objectName().isEmpty())
            AuthenticationWindow->setObjectName("AuthenticationWindow");
        AuthenticationWindow->resize(420, 476);
        AuthenticationWindow->setMinimumSize(QSize(420, 476));
        AuthenticationWindow->setMaximumSize(QSize(420, 476));
        leEmail = new QLineEdit(AuthenticationWindow);
        leEmail->setObjectName("leEmail");
        leEmail->setGeometry(QRect(130, 170, 142, 25));
        lePassword = new QLineEdit(AuthenticationWindow);
        lePassword->setObjectName("lePassword");
        lePassword->setGeometry(QRect(130, 240, 142, 25));
        pushButton = new QPushButton(AuthenticationWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 310, 80, 25));
        btnBack = new QPushButton(AuthenticationWindow);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(0, 450, 89, 25));

        retranslateUi(AuthenticationWindow);

        QMetaObject::connectSlotsByName(AuthenticationWindow);
    } // setupUi

    void retranslateUi(QDialog *AuthenticationWindow)
    {
        AuthenticationWindow->setWindowTitle(QCoreApplication::translate("AuthenticationWindow", "authentication", nullptr));
        leEmail->setText(QString());
        leEmail->setPlaceholderText(QCoreApplication::translate("AuthenticationWindow", "Email", nullptr));
        lePassword->setText(QString());
        lePassword->setPlaceholderText(QCoreApplication::translate("AuthenticationWindow", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("AuthenticationWindow", "Sign in", nullptr));
        btnBack->setText(QCoreApplication::translate("AuthenticationWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthenticationWindow: public Ui_AuthenticationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATIONWINDOW_H
