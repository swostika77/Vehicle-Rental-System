/********************************************************************************
** Form generated from reading UI file 'customerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERWINDOW_H
#define UI_CUSTOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerWindow
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableCustomerVehicle;

    void setupUi(QDialog *CustomerWindow)
    {
        if (CustomerWindow->objectName().isEmpty())
            CustomerWindow->setObjectName("CustomerWindow");
        CustomerWindow->resize(816, 360);
        buttonBox = new QDialogButtonBox(CustomerWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        tableCustomerVehicle = new QTableWidget(CustomerWindow);
        tableCustomerVehicle->setObjectName("tableCustomerVehicle");
        tableCustomerVehicle->setGeometry(QRect(210, 20, 256, 192));

        retranslateUi(CustomerWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CustomerWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CustomerWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CustomerWindow);
    } // setupUi

    void retranslateUi(QDialog *CustomerWindow)
    {
        CustomerWindow->setWindowTitle(QCoreApplication::translate("CustomerWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerWindow: public Ui_CustomerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERWINDOW_H
