#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QSqlQuery>
#include "login.h"
#include "front.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set up database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // Or your DB driver

    // Set the database filename (it will create the file if it doesn't exist)
    db.setDatabaseName("vehiclerental.db");
    if (!db.open()) {
        qDebug() << "Database open error: " << db.lastError().text();
        return -1;  // Exit app if DB can't open
    }

    QSqlQuery query;
    query.exec(
        "CREATE TABLE IF NOT EXISTS Users("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "password TEXT,"
        "role TEXT)");

    query.exec(
        "CREATE TABLE IF NOT EXISTS Vehicles("
        "id TEXT PRIMARY KEY,"
        "type TEXT,"
        "brand TEXT,"
        "model TEXT)");


    Front front;//cresting object front
    if(front.exec()==QDialog::Accepted){


    login loginWindow;
    if (loginWindow.exec() == QDialog::Accepted) {

        QString role = loginWindow.getUserRole();
        MainWindow main(role);  // pass the role
        main.show();
        return a.exec();        // Start main window only after login
    }
    }

    return 0; // if login canceled
}

