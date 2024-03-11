#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_elements();
    void startTimeEdit();
    void ProcessTime();
    // void on_start_clicked();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer = nullptr;
    int counter_seconds = 0;
    std::vector<QTime> time_arr;
    int index = 0;

};
#endif // MAINWINDOW_H
