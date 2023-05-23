/********************************************************************************
** Form generated from reading UI file 'countries.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTRIES_H
#define UI_COUNTRIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Countries
{
public:
    QPushButton *btnBack;
    QListWidget *lwServers;
    QLineEdit *leServers;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnChoose;

    void setupUi(QDialog *Countries)
    {
        if (Countries->objectName().isEmpty())
            Countries->setObjectName("Countries");
        Countries->resize(420, 476);
        Countries->setMinimumSize(QSize(420, 476));
        Countries->setMaximumSize(QSize(420, 476));
        btnBack = new QPushButton(Countries);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(0, 450, 89, 25));
        lwServers = new QListWidget(Countries);
        lwServers->setObjectName("lwServers");
        lwServers->setGeometry(QRect(50, 130, 321, 241));
        leServers = new QLineEdit(Countries);
        leServers->setObjectName("leServers");
        leServers->setGeometry(QRect(50, 40, 151, 25));
        btnAdd = new QPushButton(Countries);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(50, 80, 89, 25));
        btnDelete = new QPushButton(Countries);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(50, 380, 89, 25));
        btnChoose = new QPushButton(Countries);
        btnChoose->setObjectName("btnChoose");
        btnChoose->setGeometry(QRect(280, 380, 89, 25));

        retranslateUi(Countries);

        QMetaObject::connectSlotsByName(Countries);
    } // setupUi

    void retranslateUi(QDialog *Countries)
    {
        Countries->setWindowTitle(QCoreApplication::translate("Countries", "Dialog", nullptr));
        btnBack->setText(QCoreApplication::translate("Countries", "Back", nullptr));
        leServers->setPlaceholderText(QCoreApplication::translate("Countries", "Your Server IP: 127.0.0.1", nullptr));
        btnAdd->setText(QCoreApplication::translate("Countries", "Add", nullptr));
        btnDelete->setText(QCoreApplication::translate("Countries", "Delete", nullptr));
        btnChoose->setText(QCoreApplication::translate("Countries", "Choose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Countries: public Ui_Countries {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTRIES_H
