#include "historydialog.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include "ui_historydialog.h"
#include<QDateTime>

HistoryDialog::HistoryDialog(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryDialog)
    , currentUser(username)
{
    ui->setupUi(this);

    // Setup the table
    ui->tableHistory->setColumnCount(6);
    ui->tableHistory->setHorizontalHeaderLabels(
        {"Vehicle ID", "Booking Date", "Duration", "Status", "Total Price","Time Left"});
    ui->tableHistory->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableHistory->setEditTriggers(QAbstractItemView::NoEditTriggers);

    loadBookingHistory();
    connect(ui->pushButton, &QPushButton::clicked, this, &HistoryDialog::on_pushButton_clicked);
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}

void HistoryDialog::loadBookingHistory()
{
    ui->tableHistory->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT vehicle_id, booking_date, duration_days, status, total_price "
                  "FROM Bookings WHERE username = ? ORDER BY booking_date DESC");
    query.addBindValue(currentUser);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load history: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        QString vehicleId = query.value(0).toString();
        QDate bookingDate = query.value(1).toDate();
        int duration = query.value(2).toInt();
        QString status = query.value(3).toString();
        QString totalPrice = query.value(4).toString();

        QDate returnDate = bookingDate.addDays(duration);
        QDate currentDate = QDate::currentDate();
        QString timeLeft;

        if (status.toLower() == "returned") {
            timeLeft = "Returned";
        } else if (currentDate >= returnDate) {
            timeLeft = "Overdue";
        } else {
            int daysLeft = currentDate.daysTo(returnDate);
            timeLeft = QString::number(daysLeft) + " day(s) left";
        }

        ui->tableHistory->insertRow(row);
        ui->tableHistory->setItem(row, 0, new QTableWidgetItem(vehicleId));
        ui->tableHistory->setItem(row, 1, new QTableWidgetItem(bookingDate.toString("yyyy-MM-dd")));
        ui->tableHistory->setItem(row, 2, new QTableWidgetItem(QString::number(duration)));
        ui->tableHistory->setItem(row, 3, new QTableWidgetItem(status));
        ui->tableHistory->setItem(row, 4, new QTableWidgetItem("Rs " + totalPrice));
        ui->tableHistory->setItem(row, 5, new QTableWidgetItem(timeLeft));
        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Empty", "No bookings found.");
    } else {
        ui->tableHistory->resizeColumnsToContents();
    }
}


void HistoryDialog::on_pushButton_clicked()
{
    this->close();

}

