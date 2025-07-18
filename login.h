#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
QString getUserRole() const;
    QString getUsername() const;

private slots:
    void on_Login_clicked();

    void on_Submit_clicked();

    void on_Signup_clicked();



private:
    Ui::login *ui;
        QString loggedInRole;
    QString loggedUser;
};

#endif // LOGIN_H
