#include "customerpanel.h"
#include "ui_customerpanel.h"

customerPanel::customerPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::customerPanel)
{
    ui->setupUi(this);
}

customerPanel::~customerPanel()
{
    delete ui;
}
