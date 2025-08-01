/********************************************************************************
** Form generated from reading UI file 'viewfeedback.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFEEDBACK_H
#define UI_VIEWFEEDBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Viewfeedback
{
public:
    QTableWidget *tableFeedback;
    QLabel *label;

    void setupUi(QDialog *Viewfeedback)
    {
        if (Viewfeedback->objectName().isEmpty())
            Viewfeedback->setObjectName("Viewfeedback");
        Viewfeedback->resize(751, 544);
        tableFeedback = new QTableWidget(Viewfeedback);
        tableFeedback->setObjectName("tableFeedback");
        tableFeedback->setGeometry(QRect(80, 130, 601, 321));
        tableFeedback->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f9f9f9;  /* light neutral background */\n"
"    color: #222222;             /* dark text */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 12px;\n"
"    gridline-color: #cccccc;    /* subtle grid lines */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #e1e1e1;  /* light gray headers */\n"
"    color: #333333;             /* dark gray text */\n"
"    padding: 4px;\n"
"    border: 1px solid #cccccc;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #a0a0a0;  /* muted gray for selected row */\n"
"    color: white;\n"
"}\n"
"\n"
"QTableWidget::item:!selected:alternate {\n"
"    background-color: #f4f4f4;  /* alternate row coloring */\n"
"}\n"
"\n"
"QTableWidget::item:!selected:!alternate {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    border: none;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Remove focus border on header */\n"
"QHeaderView::section:focus {\n"
"    outlin"
                        "e: none;\n"
"}\n"
""));
        label = new QLabel(Viewfeedback);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 30, 471, 81));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    color:  #777777; \n"
"    font-size: 30px;\n"
"    font-weight: 700;\n"
"    font-family: \"Orbitron\", \"Segoe UI\", sans-serif;\n"
"    letter-spacing: 2px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
""));
        label->setScaledContents(false);

        retranslateUi(Viewfeedback);

        QMetaObject::connectSlotsByName(Viewfeedback);
    } // setupUi

    void retranslateUi(QDialog *Viewfeedback)
    {
        Viewfeedback->setWindowTitle(QCoreApplication::translate("Viewfeedback", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Viewfeedback", "\"User Feedback Overview\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewfeedback: public Ui_Viewfeedback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFEEDBACK_H
