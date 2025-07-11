/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *Login;
    QLabel *label_4;
    QPushButton *Signup;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1318, 589);
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 40, 251, 41));
        label->setStyleSheet(QString::fromUtf8("\n"
"font-family: Arial;\n"
"font-size: 14pt;\n"
"font-weight: bold;\n"
"color: #0066cc;"));
        label_2 = new QLabel(login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 120, 81, 21));
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 190, 71, 21));
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(520, 120, 291, 31));
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(520, 190, 291, 31));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        Login = new QPushButton(login);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(610, 250, 93, 29));
        label_4 = new QLabel(login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(570, 300, 171, 21));
        Signup = new QPushButton(login);
        Signup->setObjectName("Signup");
        Signup->setGeometry(QRect(610, 340, 93, 29));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "Vehicle Rental System", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("login", "Password:", nullptr));
        Login->setText(QCoreApplication::translate("login", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("login", "Do not have a account?", nullptr));
        Signup->setText(QCoreApplication::translate("login", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
