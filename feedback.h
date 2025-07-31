#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QDialog>

namespace Ui {
class Feedback;
}

class Feedback: public QDialog
{
    Q_OBJECT

public:
    explicit Feedback(const QString &username, const QString &vehicleId, QWidget *parent = nullptr);
    ~Feedback();

private slots:

    void on_btnsubmit_clicked();

private:
    Ui::Feedback*ui;
    QString m_username;
    QString m_vehicleId;
};

#endif // FEEDBACKDIALOG_H
