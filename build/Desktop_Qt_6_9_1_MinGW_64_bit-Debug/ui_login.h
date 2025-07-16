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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QFrame *frame;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *Signup;
    QLabel *label_4;
    QPushButton *Login;
    QLabel *label_3;
    QLabel *label_2;
    QToolButton *toolButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1318, 589);
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(640, 50, 141, 41));
        label->setStyleSheet(QString::fromUtf8("\n"
"font-family: Arial;\n"
"font-size: 14pt;\n"
"font-weight: bold;\n"
"color: Black;\n"
""));
        frame = new QFrame(login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(430, 170, 511, 281));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
" background-color: #f9f9f9;         \n"
"    border: 1px solid #ccc;            \n"
"    border-radius: 10px;    \n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 110, 291, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 40, 291, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Signup = new QPushButton(frame);
        Signup->setObjectName("Signup");
        Signup->setGeometry(QRect(230, 240, 93, 29));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 210, 171, 21));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"}\n"
""));
        Login = new QPushButton(frame);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(230, 170, 93, 29));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 110, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"}\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 40, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: black;\n"
"font-weight=bold;\n"
"}\n"
""));
        toolButton = new QToolButton(login);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(650, 130, 71, 61));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #f9f9f9;   \n"
"    border-radius: 10px;\n"
"    \n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #b2ebf2;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(45, 67));
        frame->raise();
        label->raise();
        toolButton->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "Login Panel", nullptr));
        Signup->setText(QCoreApplication::translate("login", "Sign up", nullptr));
        label_4->setText(QCoreApplication::translate("login", "Do not have a account?", nullptr));
        Login->setText(QCoreApplication::translate("login", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("login", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Username:", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
