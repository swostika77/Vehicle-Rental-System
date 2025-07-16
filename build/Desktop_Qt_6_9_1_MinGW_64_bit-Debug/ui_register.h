/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QLineEdit *Susername;
    QLineEdit *Spassword;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QPushButton *submit;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->setEnabled(true);
        Register->resize(1104, 588);
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 50, 131, 31));
        label->setStyleSheet(QString::fromUtf8("\n"
"font-family: Arial;\n"
"font-size: 14pt;\n"
"font-weight: bold;\n"
"color: Black;\n"
""));
        frame = new QFrame(Register);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(300, 130, 651, 291));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
" background-color: #f9f9f9;         \n"
"    border: 1px solid #ccc;            \n"
"    border-radius: 10px;    \n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 30, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 6px 10px;\n"
"}\n"
""));
        Susername = new QLineEdit(frame);
        Susername->setObjectName("Susername");
        Susername->setGeometry(QRect(150, 30, 481, 31));
        Susername->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    background-color: #ecf0f1;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #3498db;\n"
"    background-color: #ffffff;\n"
"}"));
        Spassword = new QLineEdit(frame);
        Spassword->setObjectName("Spassword");
        Spassword->setGeometry(QRect(150, 80, 481, 31));
        Spassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    background-color: #ecf0f1;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #3498db;\n"
"    background-color: #ffffff;\n"
"}"));
        Spassword->setEchoMode(QLineEdit::EchoMode::Password);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 80, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 6px 10px;\n"
"}\n"
"\n"
""));
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 140, 221, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f5f7f7;\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #aaa;\n"
"}\n"
"\n"
"/* Drop-down popup */\n"
"QComboBox QAbstractItemView {\n"
"    background: #ffffff;\n"
"    border: 1px solid #ccc;\n"
"    selection-background-color: #e6e6e6;\n"
"}\n"
"\n"
"\n"
"QPushButton#signupButton {\n"
"    background-color: #f9f9f9;\n"
"    color: #333;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"    font-size: 14px;\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 140, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 6px 10px;\n"
"}\n"
"\n"
"\n"
""));
        submit = new QPushButton(frame);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(290, 210, 93, 29));
        frame->raise();
        label->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Register", "Sign up", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Register", "Select", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Register", "Admin", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Register", "Customer", nullptr));

        label_4->setText(QCoreApplication::translate("Register", "Role:", nullptr));
        submit->setText(QCoreApplication::translate("Register", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
