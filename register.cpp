#include "register.h"
#include "ui_register.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_submit_clicked()
{
    QString username = ui->Susername->text().trimmed();
    QString password = ui->Spassword->text().trimmed();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all the fields");
        return;
    }

    qDebug() << "[Register] Current DB path:" << QSqlDatabase::database().databaseName();

    // Check if username already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Users WHERE username = ?");
    checkQuery.addBindValue(username);

    if(!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Error", "Database error while checking username");
        return;
    }

    if(checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Error", "Username already exists.");
        return;
    }



QString role = ui->comboBox->currentText().trimmed();
    if (role.compare("Customer", Qt::CaseInsensitive) == 0)
        role = "Customer";
    else
        role = "Admin";

// Insert new user
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Users (username, password, role) VALUES (?, ?, ?)");
    insertQuery.addBindValue(username);
    insertQuery.addBindValue(password);
    insertQuery.addBindValue(role); // or assign role dynamically

    if(!insertQuery.exec()) {
        QMessageBox::critical(this, "Error", "Failed to register user: " + insertQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Registered successfully!");

    accept();
}
