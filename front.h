#ifndef FRONT_H
#define FRONT_H

#include <QDialog>

namespace Ui {
class Front;
}

class Front : public QDialog
{
    Q_OBJECT

public:
    explicit Front(QWidget *parent = nullptr);
    ~Front();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Front *ui;
};

#endif // FRONT_H
