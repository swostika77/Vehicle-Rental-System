#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QInputDialog>
#include <QMessageBox>
#include "login.h"
#include <QSqlQuery>
#include <QsqlError>
#include <QSqlDatabase>
#include "customer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->continueButton, &QPushButton::clicked, this, &MainWindow::on_continueButton_clicked);

    ui->adminPanel->setVisible(false);
    ui->customerPanel->setVisible(false);

    // Set up the vehicle table
    ui->tableVehicle->setColumnCount(4);
    QStringList headers = { "ID", "Vehicle Type", "Brand", "Model" };
    ui->tableVehicle->setHorizontalHeaderLabels(headers);
    loadVehicleData();
}

MainWindow::MainWindow(const QString &role, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->continueButton, &QPushButton::clicked, this, &MainWindow::on_continueButton_clicked);

    ui->adminPanel->setVisible(false);
    ui->customerPanel->setVisible(false);
    setUserRole(role);
    // Set up the vehicle table
    ui->tableVehicle->setColumnCount(4);
    QStringList headers = { "ID", "Vehicle Type", "Brand", "Model" };
    ui->tableVehicle->setHorizontalHeaderLabels(headers);
    loadVehicleData();
}
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setUserRole(const QString &role) {
    QString normalizedRole = role.trimmed().toLower();
    userRole = normalizedRole;

    // Hide welcome screen
    ui->label->setVisible(false);
    ui->continueButton->setVisible(false);

    // Show panel based on role
    if (userRole == "admin") {
        ui->adminPanel->setVisible(true);
        ui->customerPanel->setVisible(false);
    } else if (userRole == "customer") {
        ui->adminPanel->setVisible(false);
        ui->customerPanel->setVisible(true);
    }
    else{
        ui->adminPanel->setVisible(false);
        ui->customerPanel->setVisible(false);
    }
}

void MainWindow::loadVehicleData() {
    ui->tableVehicle->setRowCount(0);
    QSqlQuery query("SELECT id, type, brand, model FROM Vehicles");

    int row = 0;
    while (query.next()) {
        ui->tableVehicle->insertRow(row);
        ui->tableVehicle->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableVehicle->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableVehicle->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableVehicle->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        row++;
    }
}

void MainWindow::on_continueButton_clicked()
{
    this->hide();  // Hide current main window (not close)

    login loginWindow;  // Show login dialog modally
    if (loginWindow.exec() == QDialog::Accepted) {
        QString role = loginWindow.getUserRole();
        setUserRole(role);  // Show proper panel
        this->show();       // Show main window again
    } else {
        this->show();  // Login failed or canceled
    }
}

void MainWindow::on_btnAdd_clicked() {
    QString id = QInputDialog::getText(this, "Vehicle ID", "Enter ID:");
    if (id.isEmpty()) return;

    QString type = QInputDialog::getText(this, "Vehicle Type", "Enter Type:");
    if (type.isEmpty()) return;

    QString brand = QInputDialog::getText(this, "Brand", "Enter Brand:");
    if (brand.isEmpty()) return;

    QString model = QInputDialog::getText(this, "Model", "Enter Model:");
    if (model.isEmpty()) return;

    // ✅ Insert into database
    QSqlQuery query;
    query.prepare("INSERT INTO Vehicles (id, type, brand, model) VALUES (?, ?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(type);
    query.addBindValue(brand);
    query.addBindValue(model);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to add vehicle: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Vehicle added successfully!");
    loadVehicleData();  // ✅ Refresh Admin panel table
}


void MainWindow::on_btnEdit_clicked() {
    int row = ui->tableVehicle->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Edit Vehicle", "Please select a vehicle to edit.");
        return;
    }

    // Get current vehicle ID (primary key)
    QString id = ui->tableVehicle->item(row, 0)->text();

    // Prompt user to edit fields
    QString newType = QInputDialog::getText(this, "Edit Vehicle Type", "Enter new vehicle type:",
                                            QLineEdit::Normal, ui->tableVehicle->item(row, 1)->text());
    if (newType.isEmpty()) return;

    QString newBrand = QInputDialog::getText(this, "Edit Brand", "Enter new brand:",
                                             QLineEdit::Normal, ui->tableVehicle->item(row, 2)->text());
    if (newBrand.isEmpty()) return;

    QString newModel = QInputDialog::getText(this, "Edit Model", "Enter new model:",
                                             QLineEdit::Normal, ui->tableVehicle->item(row, 3)->text());
    if (newModel.isEmpty()) return;

    // Update DB
    QSqlQuery query;
    query.prepare("UPDATE Vehicles SET type = ?, brand = ?, model = ? WHERE id = ?");
    query.addBindValue(newType);
    query.addBindValue(newBrand);
    query.addBindValue(newModel);
    query.addBindValue(id);

    if (!query.exec()) {
        QMessageBox::warning(this, "Database Error", "Failed to update vehicle: " + query.lastError().text());
        return;
    }

    loadVehicleData();  // Refresh table to reflect changes

    QMessageBox::information(this, "Success", "Vehicle updated successfully!");
}

void MainWindow::on_btnDelete_clicked() {
    int row = ui->tableVehicle->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Delete Vehicle", "Please select a vehicle to delete.");
        return;
    }

    QString id = ui->tableVehicle->item(row, 0)->text();

    // Confirm deletion
    if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete vehicle " + id + "?")
        == QMessageBox::No) return;

    // Delete from DB
    QSqlQuery query;
    query.prepare("DELETE FROM Vehicles WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete vehicle: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Deleted", "Vehicle deleted successfully!");

    loadVehicleData();  // Refresh table
}


void MainWindow::on_cancel_clicked()
{
        // Close the current Admin window
        this->close();

        // Show the login dialog again
        login loginWindow;
        if (loginWindow.exec() == QDialog::Accepted) {
            QString role = loginWindow.getUserRole();
            QString username = loginWindow.getUsername();

            if (role == "Admin") {
                // If Admin logs in again, reopen Admin Panel
                MainWindow adminWin(role);
                adminWin.show();
                qApp->exec();  // Start event loop again
            } else if (role == "Customer") {
                // If customer logs in, open Customer Panel
                Customer custWin(username);
                custWin.exec();
            }
        }
    }



