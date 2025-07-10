#include "mainwindow.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QApplication>
#include<QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Set up database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // Or your DB driver



    // Set the database filename (it will create the file if it doesn't exist
    db.setDatabaseName("vehiclerental.db");
    if (!db.open()) {
        qDebug() << "Database open error: " << db.lastError().text();
        return -1;  // Exit app if DB can't open
    }
    else{
        qDebug()<<"Database connected sucessfully";
        qDebug() << "Database file path:" << db.databaseName();
    }

    QSqlQuery query;
    bool sucess=query.exec(
        "CREATE TABLE IF NOT EXISTS Users("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "username TEXT UNIQUE,"
        "password TEXT,"
        "role TEXT)");
    if(!sucess){
        qDebug()<<"Failed to create Users Table:"<<query.lastError().text();
        return -1;
    }else{
        qDebug()<<"Users table ready.";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
