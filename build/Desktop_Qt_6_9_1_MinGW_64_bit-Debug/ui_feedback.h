/********************************************************************************
** Form generated from reading UI file 'feedback.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACK_H
#define UI_FEEDBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Feedback
{
public:
    QPushButton *btnsubmit;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineVehicleId;
    QLabel *label;
    QComboBox *comboRating;
    QTextEdit *textFeedback;
    QLabel *label_3;

    void setupUi(QDialog *Feedback)
    {
        if (Feedback->objectName().isEmpty())
            Feedback->setObjectName("Feedback");
        Feedback->resize(795, 528);
        btnsubmit = new QPushButton(Feedback);
        btnsubmit->setObjectName("btnsubmit");
        btnsubmit->setGeometry(QRect(350, 480, 93, 29));
        groupBox = new QGroupBox(Feedback);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 90, 671, 361));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"    font: bold 20px Arial;\n"
"    color: #666;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"}\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 111, 31));
        lineVehicleId = new QLineEdit(groupBox);
        lineVehicleId->setObjectName("lineVehicleId");
        lineVehicleId->setGeometry(QRect(190, 60, 461, 31));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 130, 211, 41));
        comboRating = new QComboBox(groupBox);
        comboRating->addItem(QString());
        comboRating->addItem(QString());
        comboRating->addItem(QString());
        comboRating->addItem(QString());
        comboRating->addItem(QString());
        comboRating->addItem(QString());
        comboRating->setObjectName("comboRating");
        comboRating->setGeometry(QRect(190, 140, 161, 31));
        comboRating->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f0f0f0;\n"
"    color: #777777;\n"
"    font: 12px Arial, sans-serif;\n"
"    padding: 4px 6px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #ccc;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    color: #555555;\n"
"    selection-background-color: #a0a0a0;\n"
"    selection-color: white;\n"
"}\n"
""));
        textFeedback = new QTextEdit(groupBox);
        textFeedback->setObjectName("textFeedback");
        textFeedback->setGeometry(QRect(190, 210, 451, 71));
        textFeedback->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #fdfdfd;\n"
"    color: #777777;\n"
"    font: 12px Arial, sans-serif;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 6px;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 240, 81, 21));

        retranslateUi(Feedback);

        QMetaObject::connectSlotsByName(Feedback);
    } // setupUi

    void retranslateUi(QDialog *Feedback)
    {
        Feedback->setWindowTitle(QCoreApplication::translate("Feedback", "Dialog", nullptr));
        btnsubmit->setText(QCoreApplication::translate("Feedback", "Submit", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Feedback", "\"GIVE FEEDBACK\"", nullptr));
        label_2->setText(QCoreApplication::translate("Feedback", "Enter Vehicle ID:", nullptr));
        lineVehicleId->setText(QString());
        label->setText(QCoreApplication::translate("Feedback", "Rate your experience(1-5):", nullptr));
        comboRating->setItemText(0, QCoreApplication::translate("Feedback", "1", nullptr));
        comboRating->setItemText(1, QCoreApplication::translate("Feedback", "2", nullptr));
        comboRating->setItemText(2, QCoreApplication::translate("Feedback", "3", nullptr));
        comboRating->setItemText(3, QCoreApplication::translate("Feedback", "4", nullptr));
        comboRating->setItemText(4, QCoreApplication::translate("Feedback", "5", nullptr));
        comboRating->setItemText(5, QString());

        label_3->setText(QCoreApplication::translate("Feedback", "Feedback:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Feedback: public Ui_Feedback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACK_H
