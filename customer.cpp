#include "customer.h"
#include "ui_customer.h"
#include<QMessageBox>
#include "bookvehicle.h"
#include<qinputdialog.h>
#include<QSqlQuery>
#include<QSqlError>
#include<mainwindow.h>
#include<login.h>
#include "historydialog.h"
#include"feedback.h"
#include<QDate>

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

    HistoryDialog dialog(loggedUser, this);
    dialog.exec();  // Show as modal window
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

  //ask if any damages
    QMessageBox::StandardButton damageBtn = QMessageBox::question(
        this,
        "Damage Check",
        "Are there any damages to the vehicle?",
        QMessageBox::Yes | QMessageBox::No
        );

    int damageFee = 0;
    QString damageType = "None";

    if (damageBtn == QMessageBox::Yes) {
        QStringList damageOptions = {
            "Scratch - Rs. 500",
            "Broken Light - Rs. 1000",
            "Major Dent - Rs. 2000",
            "Other"
        };

        damageType = QInputDialog::getItem(
            this,
            "Select Damage Type",
            "Choose damage type:",
            damageOptions,
            0,
            false,
            &ok
            );

        if (ok && !damageType.isEmpty()) {
            if (damageType.contains("Scratch")) {
                damageFee = 500;
            } else if (damageType.contains("Broken Light")) {
                damageFee = 1000;
            } else if (damageType.contains("Major Dent")) {
                damageFee = 2000;
            } else if (damageType == "Other") {
                damageType = QInputDialog::getText(
                    this,
                    "Describe Damage",
                    "Please describe the damage:",
                    QLineEdit::Normal,
                    "",
                    &ok
                    );

                if (ok && !damageType.isEmpty()) {
                    bool okFee = false;
                    damageFee = QInputDialog::getInt(
                        this,
                        "Enter Damage Fee",
                        "Enter the damage fee (Rs):",
                        0, 0, 10000, 100, &okFee
                        );

                    if (!okFee) {
                        damageFee = 0;  // fallback
                        damageType = "Other";
                    }
                }
            }
        }
    }

    // Fetch original booking fee
    QSqlQuery feeQuery;
    feeQuery.prepare("SELECT total_price FROM Bookings WHERE username = ? AND vehicle_id = ? AND status = 'Booked'");
    feeQuery.addBindValue(loggedUser);
    feeQuery.addBindValue(selectedVehicle);

    int bookingFee = 0;

    if (feeQuery.exec() && feeQuery.next()) {
        bookingFee = feeQuery.value(0).toInt();
    }

    int total_price = bookingFee + damageFee;

    QString summary = QString("Original Fee: Rs. %1\nDamage Fee: Rs. %2\n\nTotal Fee: Rs. %3")
                          .arg(bookingFee)
                          .arg(damageFee)
                          .arg(total_price);

    QMessageBox::information(this, "Total Charges", summary);

    // Update booking status to Returned
    QSqlQuery updateQuery;
    updateQuery.prepare(
        "UPDATE Bookings "
        "SET status = ?, return_date = ?, return_condition = ?, damage_fee = ?, damage_type = ? "
        "WHERE username = ? AND vehicle_id = ? AND status = 'Booked'"
        );

    QString returnDate = QDate::currentDate().toString("yyyy-MM-dd");
    QString returnCondition = (damageFee > 0) ? "Damaged" : "Good";

    updateQuery.addBindValue("Returned");
    updateQuery.addBindValue(returnDate);
    updateQuery.addBindValue(returnCondition);
    updateQuery.addBindValue(damageFee);
    updateQuery.addBindValue(damageType);
    updateQuery.addBindValue(loggedUser);
    updateQuery.addBindValue(selectedVehicle);


    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Error", "Failed to return vehicle: " + updateQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Vehicle returned successfully!\nIt is now available for booking again.");

    Feedback feedback(loggedUser, selectedVehicle, this);
    feedback.exec();

}





void Customer::on_cancel1_clicked()
{
     this->reject();
}
