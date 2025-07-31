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
        bookvehicle->resize(1479, 563);
        tableVehicle = new QTableWidget(bookvehicle);
        tableVehicle->setObjectName("tableVehicle");
        tableVehicle->setGeometry(QRect(270, 90, 921, 391));
        tableVehicle->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    alternate-background-color: #f5f9f5;\n"
"    gridline-color: #e0e0e0;\n"
"    font-size: 14px;\n"
"    border: 1px solid #cccccc;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    color: #2d2d2d;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #c8f7c5;\n"
"    color: #1b4d3e;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color:  #a8d5ba;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: 1px solid #51708a ;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #f5b041;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
""));
        btnBook = new QPushButton(bookvehicle);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(690, 500, 101, 41));
        label = new QLabel(bookvehicle);
        label->setObjectName("label");
        label->setGeometry(QRect(530, 0, 461, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    color:  #777777; \n"
"    font-size: 38px;\n"
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
