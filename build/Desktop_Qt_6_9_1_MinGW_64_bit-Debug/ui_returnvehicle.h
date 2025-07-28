/********************************************************************************
** Form generated from reading UI file 'returnvehicle.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNVEHICLE_H
#define UI_RETURNVEHICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_returnvehicle
{
public:
    QTableWidget *tableReturn;
    QPushButton *btnReturn;

    void setupUi(QDialog *returnvehicle)
    {
        if (returnvehicle->objectName().isEmpty())
            returnvehicle->setObjectName("returnvehicle");
        returnvehicle->resize(400, 300);
        tableReturn = new QTableWidget(returnvehicle);
        tableReturn->setObjectName("tableReturn");
        tableReturn->setGeometry(QRect(50, 20, 256, 192));
        btnReturn = new QPushButton(returnvehicle);
        btnReturn->setObjectName("btnReturn");
        btnReturn->setGeometry(QRect(140, 230, 93, 29));

        retranslateUi(returnvehicle);

        QMetaObject::connectSlotsByName(returnvehicle);
    } // setupUi

    void retranslateUi(QDialog *returnvehicle)
    {
        returnvehicle->setWindowTitle(QCoreApplication::translate("returnvehicle", "Dialog", nullptr));
        btnReturn->setText(QCoreApplication::translate("returnvehicle", "Retrun Vehicle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class returnvehicle: public Ui_returnvehicle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNVEHICLE_H
