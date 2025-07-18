#include "customer.h"
#include "ui_customer.h"
#include<QMessageBox>
#include "bookvehicle.h"

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
    QMessageBox::information(this, "Return Vehicle", "Here you can return your rented vehicle!");
}

