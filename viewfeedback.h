#ifndef VIEWFEEDBACK_H
#define VIEWFEEDBACK_H

#include <QDialog>



namespace Ui {
class Viewfeedback;
}

class Viewfeedback : public QDialog
{
    Q_OBJECT

public:
    explicit Viewfeedback(QWidget *parent = nullptr);
    ~Viewfeedback();

private:

    Ui::Viewfeedback *ui;
      void loadFeedback();

};

#endif // VIEWFEEDBACK_H
