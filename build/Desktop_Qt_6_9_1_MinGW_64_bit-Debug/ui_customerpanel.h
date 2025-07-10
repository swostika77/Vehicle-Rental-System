/********************************************************************************
** Form generated from reading UI file 'customerpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERPANEL_H
#define UI_CUSTOMERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_customerPanel
{
public:

    void setupUi(QDialog *customerPanel)
    {
        if (customerPanel->objectName().isEmpty())
            customerPanel->setObjectName("customerPanel");
        customerPanel->resize(400, 300);

        retranslateUi(customerPanel);

        QMetaObject::connectSlotsByName(customerPanel);
    } // setupUi

    void retranslateUi(QDialog *customerPanel)
    {
        customerPanel->setWindowTitle(QCoreApplication::translate("customerPanel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customerPanel: public Ui_customerPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERPANEL_H
