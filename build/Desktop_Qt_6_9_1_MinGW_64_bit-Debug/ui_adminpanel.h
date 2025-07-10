/********************************************************************************
** Form generated from reading UI file 'adminpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_adminPanel
{
public:

    void setupUi(QDialog *adminPanel)
    {
        if (adminPanel->objectName().isEmpty())
            adminPanel->setObjectName("adminPanel");
        adminPanel->resize(400, 300);

        retranslateUi(adminPanel);

        QMetaObject::connectSlotsByName(adminPanel);
    } // setupUi

    void retranslateUi(QDialog *adminPanel)
    {
        adminPanel->setWindowTitle(QCoreApplication::translate("adminPanel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPanel: public Ui_adminPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
