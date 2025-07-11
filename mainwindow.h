#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(const QString &role, QWidget *parent = nullptr);
    ~MainWindow();

    void setUserRole(const QString &role);

private slots:
    void on_continueButton_clicked();
    void on_btnAdd_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    QString userRole;

    void loadVehicleData();
};

#endif // MAINWINDOW_H
