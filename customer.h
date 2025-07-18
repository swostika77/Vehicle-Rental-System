#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(const QString &username, QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_btnBook_clicked();
    void on_btnHistory_clicked();
    void on_btnReturn_clicked();


private:
    Ui::Customer *ui;
    QString loggedUser;
};

#endif // CUSTOMER_H
