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
    QLabel *label_2;
    QPushButton *cancel1;

    void setupUi(QDialog *Customer)
    {
        if (Customer->objectName().isEmpty())
            Customer->setObjectName("Customer");
        Customer->resize(1459, 578);
        btnBook = new QPushButton(Customer);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(340, 110, 211, 91));
        btnBook->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 10px 20px;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1c5980;\n"
"}"));
        btnHistory = new QPushButton(Customer);
        btnHistory->setObjectName("btnHistory");
        btnHistory->setGeometry(QRect(338, 230, 211, 91));
        btnHistory->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5980;\n"
"}\n"
""));
        btnReturn = new QPushButton(Customer);
        btnReturn->setObjectName("btnReturn");
        btnReturn->setGeometry(QRect(340, 350, 211, 91));
        btnReturn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5980;\n"
"}\n"
""));
        label = new QLabel(Customer);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 10, 241, 61));
        label->setStyleSheet(QString::fromUtf8("\n"
"QLabel#label {\n"
"    color: #0abde3;\n"
"    font-size: 34px;\n"
"    font-weight: 700;\n"
"    font-family: \"Orbitron\", \"Segoe UI\", sans-serif;\n"
"    letter-spacing: 2px;\n"
"    qproperty-alignment: AlignCenter;\n"
" \n"
"}\n"
"\n"
""));
        label_2 = new QLabel(Customer);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(861, -1, 591, 571));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/Rent.jpg")));
        label_2->setScaledContents(true);
        cancel1 = new QPushButton(Customer);
        cancel1->setObjectName("cancel1");
        cancel1->setGeometry(QRect(370, 480, 148, 51));
        cancel1->setStyleSheet(QString::fromUtf8("QPushButton#cancel1{\n"
"    background-color: transparent;\n"
"    color: #666666;\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 10px 22px;\n"
"    min-width: 100px;\n"
"    transition: background-color 0.25s ease, color 0.25s ease;\n"
"}\n"
"\n"
"QPushButton#cancel1:hover {\n"
"    background-color: #f2f2f2;\n"
"    color: #444444;\n"
"}\n"
"\n"
"QPushButton#cancel1:pressed {\n"
"    background-color: #e0e0e0;\n"
"    color: #222222;\n"
"}"));

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
        label_2->setText(QString());
        cancel1->setText(QCoreApplication::translate("Customer", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customer: public Ui_Customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
