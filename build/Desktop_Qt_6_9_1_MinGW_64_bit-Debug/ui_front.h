/********************************************************************************
** Form generated from reading UI file 'front.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONT_H
#define UI_FRONT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Front
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *logo;

    void setupUi(QDialog *Front)
    {
        if (Front->objectName().isEmpty())
            Front->setObjectName("Front");
        Front->resize(1219, 692);
        Front->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: white;\n"
"    font-family: Segoe UI, Arial, sans-serif;\n"
"}\n"
""));
        label = new QLabel(Front);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 190, 481, 101));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    qproperty-alignment: AlignCenter;\n"
"    margin-top: 10px;\n"
"}\n"
""));
        label_2 = new QLabel(Front);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 260, 201, 81));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"    font-size: 20px;\n"
"    color: #34495e;\n"
"    qproperty-alignment: AlignCenter;\n"
"    margin-bottom: 10px;\n"
"font-weight:bold;\n"
"}\n"
""));
        label_3 = new QLabel(Front);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 350, 371, 71));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    qproperty-alignment: AlignCenter;\n"
"    margin-top: 10px;\n"
"font-style: Italic;\n"
"}"));
        pushButton = new QPushButton(Front);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(480, 480, 301, 81));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton {\n"
"    background-color: #808080;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    border-radius: 30px;\n"
"    border: none;\n"
"    margin: 10px auto;\n"
"}\n"
"QPushButton#pushButton:hover{\n"
"background-color:#0056b3;\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed {\n"
"    background-color: #003d80;\n"
"}"));
        logo = new QLabel(Front);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(530, 30, 201, 150));
        logo->setMinimumSize(QSize(100, 100));
        logo->setStyleSheet(QString::fromUtf8(""));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/car.jpg")));
        logo->setScaledContents(true);

        retranslateUi(Front);

        QMetaObject::connectSlotsByName(Front);
    } // setupUi

    void retranslateUi(QDialog *Front)
    {
        Front->setWindowTitle(QCoreApplication::translate("Front", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Front", "Welcome to Vehicle Rental", nullptr));
        label_2->setText(QCoreApplication::translate("Front", "System Applictaion", nullptr));
        label_3->setText(QCoreApplication::translate("Front", "\"Fast, reliable and Affordable\"", nullptr));
        pushButton->setText(QCoreApplication::translate("Front", "CLICK HERE TO CONTINUE", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Front: public Ui_Front {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONT_H
