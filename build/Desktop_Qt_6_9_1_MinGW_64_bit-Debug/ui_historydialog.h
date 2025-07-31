/********************************************************************************
** Form generated from reading UI file 'historydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDIALOG_H
#define UI_HISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryDialog
{
public:
    QTableWidget *tableHistory;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *HistoryDialog)
    {
        if (HistoryDialog->objectName().isEmpty())
            HistoryDialog->setObjectName("HistoryDialog");
        HistoryDialog->resize(1340, 704);
        tableHistory = new QTableWidget(HistoryDialog);
        tableHistory->setObjectName("tableHistory");
        tableHistory->setGeometry(QRect(210, 140, 981, 401));
        tableHistory->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
"\n"
"QHeaderView::section {\n"
"    background-color: #a3c1d1;\n"
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
"}"));
        label = new QLabel(HistoryDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(610, 20, 161, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    color:  #777777; \n"
"    font-size: 38px;\n"
"    font-weight: 700;\n"
"    font-family: \"Orbitron\", \"Segoe UI\", sans-serif;\n"
"    letter-spacing: 2px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
""));
        pushButton = new QPushButton(HistoryDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(670, 600, 111, 41));

        retranslateUi(HistoryDialog);

        QMetaObject::connectSlotsByName(HistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryDialog)
    {
        HistoryDialog->setWindowTitle(QCoreApplication::translate("HistoryDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("HistoryDialog", "History", nullptr));
        pushButton->setText(QCoreApplication::translate("HistoryDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryDialog: public Ui_HistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDIALOG_H
