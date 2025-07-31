#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>

namespace Ui {
class HistoryDialog;
}

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(const QString &username, QWidget *parent = nullptr);
    ~HistoryDialog();

private slots:
    void on_pushButton_clicked();

private:
    void loadBookingHistory();

    Ui::HistoryDialog *ui;
    QString currentUser;
};

#endif // HISTORYDIALOG_H
