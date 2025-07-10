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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Susername;
    QLineEdit *Spassword;
    QComboBox *comboBox;
    QPushButton *submit;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->setEnabled(true);
        Register->resize(1104, 588);
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 30, 191, 31));
        label_2 = new QLabel(Register);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 120, 81, 31));
        label_3 = new QLabel(Register);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 180, 71, 21));
        label_4 = new QLabel(Register);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 240, 62, 20));
        Susername = new QLineEdit(Register);
        Susername->setObjectName("Susername");
        Susername->setGeometry(QRect(170, 120, 481, 31));
        Spassword = new QLineEdit(Register);
        Spassword->setObjectName("Spassword");
        Spassword->setGeometry(QRect(170, 180, 481, 31));
        Spassword->setEchoMode(QLineEdit::EchoMode::Password);
        comboBox = new QComboBox(Register);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(170, 240, 221, 31));
        submit = new QPushButton(Register);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(230, 310, 93, 29));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Register", "Sign up!", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "Role:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Register", "Select", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Register", "Admin", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Register", "Customer", nullptr));

        submit->setText(QCoreApplication::translate("Register", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
