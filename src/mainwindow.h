#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
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
    void AddElements();
    void DeleteElements();
    void StartTimer();
    void ProcessTime();
    void StopTimer();
    void SaveSettings();
    void LoadSettings();

private:
    Ui::MainWindow *ui;

    QSettings settings;
    QTimer *timer;
    std::vector<QTime> time_arr;
    int index = 0;

};
#endif // MAINWINDOW_H
