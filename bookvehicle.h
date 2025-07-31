#ifndef BOOKVEHICLE_H
#define BOOKVEHICLE_H

#include <QDialog>

namespace Ui {
class bookvehicle;
}

class bookvehicle : public QDialog
{
    Q_OBJECT

public:
    explicit bookvehicle(const QString &username, QWidget *parent = nullptr);
    ~bookvehicle();


private slots:
    void on_btnBook_clicked();


    void on_tableVehicle_cellActivated(int row, int column);

private:
    void loadAvailableVehicles();
    Ui::bookvehicle *ui;
    QString currentUser;
};

#endif // BOOKVEHICLE_H
