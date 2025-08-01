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


    query.exec("ALTER TABLE Bookings ADD COLUMN return_date TEXT");
    query.exec("ALTER TABLE Bookings ADD COLUMN return_condition TEXT");

    query.exec("ALTER TABLE Bookings ADD COLUMN damage_fee INTEGER DEFAULT 0");
    query.exec("ALTER TABLE Bookings ADD COLUMN damage_type TEXT DEFAULT 'None'");

    /*if (query.exec("DELETE FROM Feedbacks")) {
        qDebug() << "All feedback data deleted successfully.";
    } else {
        qDebug() << "Failed to delete feedback data:" << query.lastError().text();
    }*/


    /*query.prepare("DELETE FROM Bookings WHERE username = :user");
    query.bindValue(":user", "jk");

    if (query.exec()) {
        qDebug() << "All feedback entries by user 'iu' deleted.";
    } else {
        qDebug() << "Error deleting user feedback:" << query.lastError().text();
    }
*/


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

    // Show front dialog first (optional)
    Front frontDialog;
    if (frontDialog.exec() != QDialog::Accepted) {
        return 0;  // user canceled front dialog, exit app
    }

    while (true) {
        login loginWindow;
        if (loginWindow.exec() != QDialog::Accepted) {
            break;  // User canceled login, exit app
        }

        QString role = loginWindow.getUserRole();
        QString username = loginWindow.getUsername();

        if (role == "Admin") {
            MainWindow adminWin(role);
            adminWin.show();
            return a.exec();  // Run main event loop with admin main window
        }
        else if (role == "Customer") {
            Customer custWin(username);
            int result = custWin.exec();  // modal dialog

            if (result == QDialog::Rejected) {
                // User clicked Cancel in customer panel, go back to login
                continue;
            }
            else {
                // Customer dialog accepted or closed normally, exit app
                break;
            }
        }
    }

    return 0;
}
