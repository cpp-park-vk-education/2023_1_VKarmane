/********************************************************************************
** Form generated from reading UI file 'configurationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONWINDOW_H
#define UI_CONFIGURATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationWindow
{
public:
    QPushButton *btnSave;
    QPlainTextEdit *pteConfiguration;
    QLabel *label;
    QPushButton *btnBack;

    void setupUi(QDialog *ConfigurationWindow)
    {
        if (ConfigurationWindow->objectName().isEmpty())
            ConfigurationWindow->setObjectName("ConfigurationWindow");
        ConfigurationWindow->setWindowModality(Qt::NonModal);
        ConfigurationWindow->resize(420, 476);
        ConfigurationWindow->setMinimumSize(QSize(420, 476));
        ConfigurationWindow->setMaximumSize(QSize(420, 476));
        btnSave = new QPushButton(ConfigurationWindow);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(160, 410, 89, 25));
        pteConfiguration = new QPlainTextEdit(ConfigurationWindow);
        pteConfiguration->setObjectName("pteConfiguration");
        pteConfiguration->setGeometry(QRect(20, 50, 381, 351));
        label = new QLabel(ConfigurationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 201, 20));
        btnBack = new QPushButton(ConfigurationWindow);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(0, 450, 89, 25));

        retranslateUi(ConfigurationWindow);

        QMetaObject::connectSlotsByName(ConfigurationWindow);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationWindow)
    {
        ConfigurationWindow->setWindowTitle(QCoreApplication::translate("ConfigurationWindow", "Configuration", nullptr));
        btnSave->setText(QCoreApplication::translate("ConfigurationWindow", "Save", nullptr));
        pteConfiguration->setPlaceholderText(QCoreApplication::translate("ConfigurationWindow", "Your url: www.vk.com", nullptr));
        label->setText(QCoreApplication::translate("ConfigurationWindow", "Change yout configurations:", nullptr));
        btnBack->setText(QCoreApplication::translate("ConfigurationWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationWindow: public Ui_ConfigurationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONWINDOW_H
