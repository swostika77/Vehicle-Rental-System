/********************************************************************************
** Form generated from reading UI file 'bookvehicle.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKVEHICLE_H
#define UI_BOOKVEHICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_bookvehicle
{
public:
    QTableWidget *tableVehicle;
    QPushButton *btnBook;
    QLabel *label;

    void setupUi(QDialog *bookvehicle)
    {
        if (bookvehicle->objectName().isEmpty())
            bookvehicle->setObjectName("bookvehicle");
        bookvehicle->resize(1456, 608);
        tableVehicle = new QTableWidget(bookvehicle);
        tableVehicle->setObjectName("tableVehicle");
        tableVehicle->setGeometry(QRect(430, 140, 501, 301));
        btnBook = new QPushButton(bookvehicle);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(640, 480, 101, 41));
        label = new QLabel(bookvehicle);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 20, 461, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    color: #0abde3;\n"
"    font-size: 34px;\n"
"    font-weight: 700;\n"
"    font-family: \"Orbitron\", \"Segoe UI\", sans-serif;\n"
"    letter-spacing: 2px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
""));

        retranslateUi(bookvehicle);

        QMetaObject::connectSlotsByName(bookvehicle);
    } // setupUi

    void retranslateUi(QDialog *bookvehicle)
    {
        bookvehicle->setWindowTitle(QCoreApplication::translate("bookvehicle", "Dialog", nullptr));
        btnBook->setText(QCoreApplication::translate("bookvehicle", "Book", nullptr));
        label->setText(QCoreApplication::translate("bookvehicle", "Book your Vehicle now!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookvehicle: public Ui_bookvehicle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKVEHICLE_H
