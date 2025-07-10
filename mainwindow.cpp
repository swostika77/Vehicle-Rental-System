#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->continueButton, &QPushButton::clicked, this, &MainWindow::on_continueButton_clicked);

    ui->adminPanel->setVisible(false);
    ui->customerPanel->setVisible(false);
}


MainWindow::MainWindow(const QString &role,QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 connect(ui->continueButton, &QPushButton::clicked, this, &MainWindow::on_continueButton_clicked);
    ui->adminPanel->setVisible(false);
 ui->customerPanel->setVisible(false);
    setUserRole(role);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_continueButton_clicked()
{
    login *loginWindow = new login();
    loginWindow->show();
    this->close();  // optional: closes MainWindow after opening Login
}


void MainWindow::setUserRole(const QString &role){
    userRole=role;
    //Hide initial welcome Ui
    ui->label->setVisible(false);
    ui->continueButton->setVisible(false);

    if(userRole=="Admin"){
        ui->adminPanel->setVisible(true);
        ui->customerPanel->setVisible(false);
    }
    else if(userRole=="Customer"){
        ui->adminPanel->setVisible(false);
        ui->customerPanel->setVisible(true);
    }
}
