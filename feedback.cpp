
#include "feedback.h"
#include "ui_feedback.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Feedback::Feedback(const QString &username, const QString &vehicleId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Feedback),
    m_username(username)

{
    ui->setupUi(this);


    if (ui->comboRating->count() == 0) {
        for (int i = 1; i <= 5; ++i) {
            ui->comboRating->addItem(QString::number(i));
        }
    }

}


Feedback::~Feedback()
{
    delete ui;
}



void Feedback::on_btnsubmit_clicked()
{QSqlQuery query;
        QString feedbackText = ui->textFeedback->toPlainText();
        int rating = ui->comboRating->currentText().toInt();
         QString vehicleId = ui->lineVehicleId->text(); // get it from user input

        query.prepare("INSERT INTO Feedbacks (username, vehicle_id, feedback_text, rating) "
                      "VALUES (:username, :vehicle_id, :feedback_text, :rating)");
        query.bindValue(":username", m_username);

        query.bindValue(":vehicle_id", vehicleId);

        query.bindValue(":feedback_text", feedbackText);
        query.bindValue(":rating", rating);

        qDebug() << "Inserting Feedback: username=" << m_username
                 << " vehicle_id=" << m_vehicleId
                 << " rating=" << rating
                 << " feedback=" << feedbackText;

        QMessageBox::information(this, "Debug Info", QString("User: %1\nVehicle: %2\nRating: %3")
                                                         .arg(m_username)
                                                         .arg(m_vehicleId)
                                                         .arg(rating));


        if (!query.exec()) {
            qDebug() << "Failed to submit feedback:" << query.lastError().text();
            QMessageBox::warning(this, "Error", "Failed to submit feedback.");
        } else {
            QMessageBox::information(this, "Success", "Thank you for your feedback!");
            this->accept();
        }
    }

