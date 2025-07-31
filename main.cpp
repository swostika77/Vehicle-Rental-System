#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

#include "front.h"
#include "login.h"
#include "mainwindow.h"
#include "customer.h"

void setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("vehiclerental.db");
    if (!db.open()) {
        qDebug() << "Database Error:" << db.lastError().text();
        exit(1);

    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS Users("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT UNIQUE,"
               "password TEXT,"
               "role TEXT)");

    query.exec("CREATE TABLE IF NOT EXISTS Vehicles("
               "id TEXT PRIMARY KEY,"
               "type TEXT,"
               "brand TEXT,"
               "model TEXT)");

    query.exec("CREATE TABLE IF NOT EXISTS Bookings("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT,"
               "vehicle_id TEXT,"
               "booking_date TEXT,"
               "status TEXT,"
               "duration_days INTEGER,"
               "total_price REAL)");

    query.exec("CREATE TABLE IF NOT EXISTS Feedbacks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT, "
               "vehicle_id TEXT, "
               "feedback_text TEXT, "
               "rating INTEGER)");




    /*if (query.exec("DELETE FROM Feedbacks")) {
        qDebug() << "All feedback data deleted successfully.";
    } else {
        qDebug() << "Failed to delete feedback data:" << query.lastError().text();
    }*/




    // Sample Vehicles
    QSqlQuery check;
    check.exec("SELECT COUNT(*) FROM Vehicles");
    if (check.next()) {
        qDebug() << "[INFO] Vehicles table currently has:" << check.value(0).toInt() << "records.";
    }
}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    setupDatabase();
    Front frontDialog;
    if (frontDialog.exec() == QDialog::Accepted) {
    login loginWindow;
    if (loginWindow.exec() == QDialog::Accepted) {
        QString role = loginWindow.getUserRole();
        QString username = loginWindow.getUsername();

        if (role == "Admin") {
            MainWindow adminWin(role);
            adminWin.show();
            return a.exec();
        } else if (role == "Customer") {
            Customer custWin(username);
            custWin.exec();
        }
    }
    }

    return 0;
}
