#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QInputDialog>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableVehicle->setColumnCount(4);
    QStringList headers ={"ID","Brand","model"};
    ui->tableVehicle->setHorizontalHeaderLabels(headers);
    loadVehicleData();

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::loadVehicleData(){
    ui->tableVehicle->insertRow(0);
    ui->tableVehicle->setItem(0,0,new QTableWidgetItem("v001"));
    ui->tableVehicle->setItem(0,1,new QTableWidgetItem("car"));
    ui->tableVehicle->setItem(0,2,new QTableWidgetItem("Toyota"));
    ui->tableVehicle->setItem(0,3,new QTableWidgetItem("corolla"));
}
void MainWindow::on_btnAdd_clicked()
{

    int row =ui->tableVehicle->rowCount();
    ui->tableVehicle->insertRow(row);
    QString id=QInputDialog:: getText(this ,"Vechicle ID","Enter ID:");
    QString vehicletype =QInputDialog::getText(this,"VehicleType","Enter Vehicle Type");
    QString brand=QInputDialog::getText(this,"Brand","Enter Brand");
    QString model=QInputDialog::getText(this,"Model","Enter Model");

    ui->tableVehicle->setItem(row,0,new QTableWidgetItem(id));
    ui->tableVehicle->setItem(row,1,new QTableWidgetItem(vehicletype));
    ui->tableVehicle->setItem(row,2,new QTableWidgetItem (brand));
    ui->tableVehicle->setItem(row,3,new QTableWidgetItem(model));


}
void MainWindow::on_btnEdit_clicked()
{
    int row = ui->tableVehicle->currentRow();
    if (row < 0) return;

    QString id = QInputDialog::getText(this, "Edit ID", "New ID:", QLineEdit::Normal, ui->tableVehicle->item(row, 0)->text());
    QString vehicletype = QInputDialog::getText(this, "Edit vehicletype", "New Vehicle type:", QLineEdit::Normal, ui->tableVehicle->item(row, 1)->text());
    QString brand = QInputDialog::getText(this, "Edit Brand", "New Brand:", QLineEdit::Normal, ui->tableVehicle->item(row, 2)->text());
    QString model = QInputDialog::getText(this, "Edit Model", "New Model:", QLineEdit::Normal, ui->tableVehicle->item(row, 3)->text());



    ui->tableVehicle->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableVehicle->setItem(row,0,  new QTableWidgetItem(vehicletype));
    ui->tableVehicle->setItem(row, 1, new QTableWidgetItem(brand));
    ui->tableVehicle->setItem(row, 2, new QTableWidgetItem(model));
}
void MainWindow::on_btnDelete_clicked()
{
    int row = ui->tableVehicle->currentRow();
    if (row < 0) return;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->tableVehicle->removeRow(row);
    }
}



