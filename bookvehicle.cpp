#include "bookvehicle.h"
#include "ui_bookvehicle.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include<QInputDialog>
bookvehicle::bookvehicle(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookvehicle)
    , currentUser(username)
{
    ui->setupUi(this);

    ui->tableVehicle->setColumnCount(4);
    ui->tableVehicle->setHorizontalHeaderLabels({"ID", "Type", "Brand", "Model"});
    ui->tableVehicle->setSelectionBehavior(QAbstractItemView::SelectRows);

    loadAvailableVehicles();

}


bookvehicle::~bookvehicle()
{
    delete ui;
}

void bookvehicle::loadAvailableVehicles() {
    ui->tableVehicle->setRowCount(0);

    QSqlQuery query;
    if (!query.exec(
            "SELECT v.id, v.type, v.brand, v.model "
            "FROM Vehicles v " )) {
        QMessageBox::critical(this, "DB Error", query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableVehicle->insertRow(row);
        ui->tableVehicle->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        ui->tableVehicle->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Type
        ui->tableVehicle->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Brand
        ui->tableVehicle->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Model
        row++;
    }

    // ✅ If no available vehicles
    if (row == 0) {
        QMessageBox::information(this, "No Vehicles", "No available vehicles right now.");
    }
}

double getRatebyType(const QString &type){
    QString lowerType=type.trimmed().toLower();
    if(lowerType=="car")
        return 50;
    if(lowerType=="bike")
        return 20;
    if(lowerType=="van")return 40;
    return 30;

}
void bookvehicle::on_btnBook_clicked() {
    int row = ui->tableVehicle->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a vehicle to book!");
        return;
    }

    QString vehicleId = ui->tableVehicle->item(row, 0)->text();
    QString vehicleType = ui->tableVehicle->item(row, 1)->text();

    //asking for the booking duration;
    bool ok;
    int days = QInputDialog::getInt(this, "Booking Duration", "Enter number of days:", 1, 1, 365, 1, &ok);

    if(!ok)
        return;

    double dailyRate=getRatebyType(vehicleType);
    double totalPrice=days*dailyRate;

    QString confirmMsg = QString(
                             "Vehicle: %1\nType: %2\nDays: %3\nRate: $%4/day\n\nTotal Price: $%5\n\nConfirm booking?"
                             ).arg(vehicleId)
                             .arg(vehicleType)
                             .arg(days)
                             .arg(dailyRate)
                             .arg(totalPrice);


    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirm Booking", confirmMsg,
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply != QMessageBox::Yes) {
        return; // User canceled
    }

    //insert booking into DB
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString status="Booked";
    QSqlQuery query;
    query.prepare("INSERT INTO Bookings (username, vehicle_id, booking_date, status,duration_days,total_price)"
                   "VALUES (?, ?, ?,?,?,?)");
    query.addBindValue(currentUser);
    query.addBindValue(vehicleId);
    query.addBindValue(date);
    query.addBindValue(status);
    query.addBindValue(days);
    query.addBindValue(totalPrice);


    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to book vehicle: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Vehicle booked successfully!");

    accept();


}
