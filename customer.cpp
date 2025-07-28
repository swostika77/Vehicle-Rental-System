#include "customer.h"
#include "ui_customer.h"
#include<QMessageBox>
#include "bookvehicle.h"
#include<qinputdialog.h>
#include<QSqlQuery>
#include<QSqlError>
#include<mainwindow.h>
#include<login.h>
    Customer::Customer(const QString &username, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Customer),
    loggedUser(username) {
    ui->setupUi(this);

}
Customer::~Customer()
{
    delete ui;
}

void Customer::on_btnBook_clicked()
{
    bookvehicle dialog(loggedUser);
    dialog.exec();  // Open booking dialog
}


// SLOT: View History
void Customer::on_btnHistory_clicked() {
    QMessageBox::information(this, "Booking History", "Here you can view your booking history!");
}

// SLOT: Return Vehicle
void Customer::on_btnReturn_clicked() {
    // Fetch currently booked vehicles for THIS user
    QSqlQuery query;
    query.prepare(
        "SELECT vehicle_id FROM Bookings "
        "WHERE username = ? AND status = 'Booked'"
        );
    query.addBindValue(loggedUser);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to fetch booked vehicles: " + query.lastError().text());
        return;
    }

    QStringList bookedVehicles;
    while (query.next()) {
        bookedVehicles << query.value(0).toString();  // vehicle IDs
    }

    if (bookedVehicles.isEmpty()) {
        QMessageBox::information(this, "No Booked Vehicles", "You have no booked vehicles to return.");
        return;
    }

    // Let user pick which vehicle to return
    bool ok;
    QString selectedVehicle = QInputDialog::getItem(
        this,
        "Return Vehicle",
        "Select a vehicle to return:",
        bookedVehicles,
        0,
        false,
        &ok
        );

    if (!ok || selectedVehicle.isEmpty()) return;

   // Confirm with user
        QMessageBox::StandardButton confirm = QMessageBox::question(
            this,
            "Confirm Return",
            "Are you sure you want to return " + selectedVehicle + "?",
            QMessageBox::Yes | QMessageBox::No
            );

    if (confirm != QMessageBox::Yes) return;

    // 5️⃣ Update DB → set status = Returned
    QSqlQuery updateQuery;
    updateQuery.prepare(
        "UPDATE Bookings "
        "SET status = 'Returned' "
        "WHERE username = ? AND vehicle_id = ? AND status = 'Booked'"
        );
    updateQuery.addBindValue(loggedUser);
    updateQuery.addBindValue(selectedVehicle);

    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Error", "Failed to return vehicle: " + updateQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Vehicle returned successfully!\nIt is now available for booking again.");
}


void Customer::on_cancel1_clicked()
{
    this->close();  // Close Customer panel

    // Show the login dialog again
    login loginWindow;
    if (loginWindow.exec() == QDialog::Accepted) {
        QString role = loginWindow.getUserRole();
        QString username = loginWindow.getUsername();

        if (role == "Admin") {
            MainWindow adminWin(role);
            adminWin.show();
            qApp->exec();  // Restart event loop
        } else if (role == "Customer") {
            Customer custWin(username);
            custWin.exec();
        }
    }
}


