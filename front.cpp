#include "front.h"
#include "ui_front.h"
#include <QDebug>
#include <QPixmap>
#include<QFile>

Front::Front(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Front)
{
    ui->setupUi(this);
    QPixmap pix(":/img/cars.png");
                int w=ui->logo->width();
    int h=ui->logo->height();
                ui->logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

Front::~Front()
{
    delete ui;
}
void Front::on_pushButton_clicked(){
    accept(); //closes welcome screen
}
