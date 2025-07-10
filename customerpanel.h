#ifndef CUSTOMERPANEL_H
#define CUSTOMERPANEL_H

#include <QDialog>

namespace Ui {
class customerPanel;
}

class customerPanel : public QDialog
{
    Q_OBJECT

public:
    explicit customerPanel(QWidget *parent = nullptr);
    ~customerPanel();

private:
    Ui::customerPanel *ui;
};

#endif // CUSTOMERPANEL_H
