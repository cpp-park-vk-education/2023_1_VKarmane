/********************************************************************************
** Form generated from reading UI file 'staticswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICSWINDOW_H
#define UI_STATICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StaticsWindow
{
public:
    QPushButton *btnBack;

    void setupUi(QDialog *StaticsWindow)
    {
        if (StaticsWindow->objectName().isEmpty())
            StaticsWindow->setObjectName("StaticsWindow");
        StaticsWindow->resize(420, 476);
        StaticsWindow->setMinimumSize(QSize(420, 476));
        StaticsWindow->setMaximumSize(QSize(420, 476));
        btnBack = new QPushButton(StaticsWindow);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(0, 450, 89, 25));

        retranslateUi(StaticsWindow);

        QMetaObject::connectSlotsByName(StaticsWindow);
    } // setupUi

    void retranslateUi(QDialog *StaticsWindow)
    {
        StaticsWindow->setWindowTitle(QCoreApplication::translate("StaticsWindow", "Statistics", nullptr));
        btnBack->setText(QCoreApplication::translate("StaticsWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaticsWindow: public Ui_StaticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICSWINDOW_H
