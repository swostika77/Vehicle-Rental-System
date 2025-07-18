/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Customer
{
public:
    QPushButton *btnBook;
    QPushButton *btnHistory;
    QPushButton *btnReturn;
    QLabel *label;

    void setupUi(QDialog *Customer)
    {
        if (Customer->objectName().isEmpty())
            Customer->setObjectName("Customer");
        Customer->resize(1450, 677);
        btnBook = new QPushButton(Customer);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(660, 210, 171, 91));
        btnHistory = new QPushButton(Customer);
        btnHistory->setObjectName("btnHistory");
        btnHistory->setGeometry(QRect(660, 370, 171, 101));
        btnReturn = new QPushButton(Customer);
        btnReturn->setObjectName("btnReturn");
        btnReturn->setGeometry(QRect(660, 530, 171, 101));
        label = new QLabel(Customer);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 70, 151, 81));
        label->setStyleSheet(QString::fromUtf8("\n"
"font-family: Arial;\n"
"font-size: 14pt;\n"
"font-weight: bold;\n"
"color: Black;\n"
""));

        retranslateUi(Customer);

        QMetaObject::connectSlotsByName(Customer);
    } // setupUi

    void retranslateUi(QDialog *Customer)
    {
        Customer->setWindowTitle(QCoreApplication::translate("Customer", "Dialog", nullptr));
        btnBook->setText(QCoreApplication::translate("Customer", "Book Vehicle", nullptr));
        btnHistory->setText(QCoreApplication::translate("Customer", "View booking History", nullptr));
        btnReturn->setText(QCoreApplication::translate("Customer", "Return Vehicle", nullptr));
        label->setText(QCoreApplication::translate("Customer", "WELCOME!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customer: public Ui_Customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
