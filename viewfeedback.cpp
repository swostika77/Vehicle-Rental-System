#include "viewfeedback.h"
#include "ui_viewfeedback.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidgetItem>
#include <QMessageBox>

Viewfeedback::Viewfeedback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Viewfeedback)
{
    ui->setupUi(this);

    qDebug() << "Viewfeedback dialog created";
    ui->tableFeedback->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    loadFeedback();
}

Viewfeedback::~Viewfeedback()
{
    delete ui;
}

void Viewfeedback::loadFeedback()
{
    qDebug() << "Loading feedback...";

    ui->tableFeedback->setRowCount(0);
    ui->tableFeedback->setColumnCount(4);
    ui->tableFeedback->setHorizontalHeaderLabels({"Username", "Vehicle ID", "Rating", "feedback_text"});

    QSqlQuery query;
    if (!query.exec("SELECT username, vehicle_id, rating, feedback_text FROM Feedbacks")) {
        qDebug() << "Query failed:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to load feedback: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        qDebug() << "Row" << row << ":"
                 << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toInt()
                 << query.value(3).toString();

        ui->tableFeedback->insertRow(row);
        for (int col = 0; col < 4; ++col) {
            for (int col = 0; col < 4; ++col) {
                QVariant val = query.value(col);
                QString displayText;

                if (col == 2) {  // Rating column
                    displayText = QString::number(val.toInt());
                } else {
                    displayText = val.toString();
                }

                ui->tableFeedback->setItem(row, col, new QTableWidgetItem(displayText));
            }

        }
    qDebug() << "Loaded" << row << "feedback entries";
}
}
