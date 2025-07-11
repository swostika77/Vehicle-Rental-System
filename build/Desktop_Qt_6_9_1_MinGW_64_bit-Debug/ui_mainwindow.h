/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *continueButton;
    QWidget *adminPanel;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QWidget *customerPanel;
    QTableWidget *tableVehicle;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 80, 200, 56));
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(290, 280, 200, 30));
        adminPanel = new QWidget(centralwidget);
        adminPanel->setObjectName("adminPanel");
        adminPanel->setGeometry(QRect(50, 350, 700, 200));
        horizontalLayout = new QHBoxLayout(adminPanel);
        horizontalLayout->setObjectName("horizontalLayout");
        btnAdd = new QPushButton(adminPanel);
        btnAdd->setObjectName("btnAdd");

        horizontalLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(adminPanel);
        btnEdit->setObjectName("btnEdit");

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(adminPanel);
        btnDelete->setObjectName("btnDelete");

        horizontalLayout->addWidget(btnDelete);

        customerPanel = new QWidget(centralwidget);
        customerPanel->setObjectName("customerPanel");
        customerPanel->setGeometry(QRect(60, 140, 120, 80));
        tableVehicle = new QTableWidget(centralwidget);
        tableVehicle->setObjectName("tableVehicle");
        tableVehicle->setGeometry(QRect(180, 150, 431, 221));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 100, 111, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vehicle Rental System", nullptr));
        continueButton->setText(QCoreApplication::translate("MainWindow", "Click here to Continue.", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ADMIN PANEL!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
