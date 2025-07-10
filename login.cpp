#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "mainwindow.h"
#include "register.h"
#include <QSqlError>
#include<QDebug>


login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_Login_clicked()
{
    QString username = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();
    qDebug() << "Trying login with username:" << username << "and password:" << password;

    qDebug() << "[Login] Current DB path:" << QSqlDatabase::database().databaseName();


    QSqlQuery query;
    query.prepare("SELECT role FROM Users WHERE username=? AND password=?");
    query.addBindValue(username);
    query.addBindValue(password);

    if(!query.exec()){
        qDebug()<<"Login query failed:"<<query.lastError().text();
        QMessageBox::warning(this,"Login Failed","Database query error");
        return ;
    }

    if (query.next()) {
        // Successful login
        QString role = query.value(0).toString();
        QMessageBox::information(this, "Login", "Login Successful! Role: " + role);

        MainWindow *main = new MainWindow();
        main->setUserRole(role);
        main->show();
        this->close();
    }
    else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}



void login::on_Submit_clicked()
{
    Register *reg = new Register();
    reg->show();
}


void login::on_Signup_clicked()
{
    Register *regWindow=new Register();
    regWindow->show();
    this->close();
}


/*void login::on_Login_clicked()
{
    QString username = ui->Login->text();
    QString password = ui->Signup->text();

    QSqlQuery query;
    query.prepare("SELECT role FROM Users WHERE username=? AND password=?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (query.exec() && query.next()) {
        QString role = query.value(0).toString();
        QMessageBox::information(this, "Login", "Login Successful! Role: " + role);

        MainWindow *main = new MainWindow(role);
        main->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

*/

