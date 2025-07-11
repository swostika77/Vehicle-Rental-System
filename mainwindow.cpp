#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QInputDialog>
#include <QMessageBox>
#include "login.h"
#include <QSqlQuery>
#include <QsqlError>
#include <QSqlDatabase>

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
    userRole = role;

    // Hide welcome screen
    ui->label->setVisible(false);
    ui->continueButton->setVisible(false);

    // Show panel based on role
    if (userRole == "Admin") {
        ui->adminPanel->setVisible(true);
        ui->customerPanel->setVisible(false);
    } else if (userRole == "Customer") {
        ui->adminPanel->setVisible(false);
        ui->customerPanel->setVisible(true);
    }
}

void MainWindow::loadVehicleData() {
    ui->tableVehicle->setRowCount(0);  // Clear previous rows
    ui->tableVehicle->insertRow(0);
    ui->tableVehicle->setItem(0, 0, new QTableWidgetItem("v001"));
    ui->tableVehicle->setItem(0, 1, new QTableWidgetItem("Car"));
    ui->tableVehicle->setItem(0, 2, new QTableWidgetItem("Toyota"));
    ui->tableVehicle->setItem(0, 3, new QTableWidgetItem("Corolla"));
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
    int row = ui->tableVehicle->rowCount();
    ui->tableVehicle->insertRow(row);

    QString id = QInputDialog::getText(this, "Vehicle ID", "Enter ID:");
    QString type = QInputDialog::getText(this, "Vehicle Type", "Enter Type:");
    QString brand = QInputDialog::getText(this, "Brand", "Enter Brand:");
    QString model = QInputDialog::getText(this, "Model", "Enter Model:");

    ui->tableVehicle->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableVehicle->setItem(row, 1, new QTableWidgetItem(type));
    ui->tableVehicle->setItem(row, 2, new QTableWidgetItem(brand));
    ui->tableVehicle->setItem(row, 3, new QTableWidgetItem(model));
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
    // You can later add logic to delete selected row
    int currentRow = ui->tableVehicle->currentRow();
    if (currentRow >= 0) {
        ui->tableVehicle->removeRow(currentRow);
        QMessageBox::information(this, "Deleted", "Vehicle deleted successfully.");
    } else {
        QMessageBox::warning(this, "Delete", "No row selected to delete.");
    }
}

