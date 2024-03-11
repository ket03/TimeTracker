#include "mainwindow.h"
#include "ui_mainwindow.h"

// refactor
// change principle
// custom front
// fix window size
// save data
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stop->hide();

    connect(ui->add, SIGNAL(clicked()), this, SLOT(add_elements()));
    connect(ui->start, SIGNAL(clicked()), this, SLOT(startTimeEdit()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_elements()
{
    QTime time(0, 0);
    QString task = ui->task->text();
    QList<QListWidgetItem*> items = ui->todo_list->findItems(task, Qt::MatchExactly);
    if (items.isEmpty() && !task.isEmpty()) {
        ui->todo_list->addItem(task);
        ui->timer_list->addItem("00:00:00");
        time_arr.push_back(time);
    }

}

void MainWindow::startTimeEdit()
{
    QList<QListWidgetItem*> selectedItems = ui->todo_list->selectedItems();
    if (!selectedItems.isEmpty() && ui->todo_list->count() != 0) {
        QListWidgetItem* selectedItem = selectedItems.first();
        timer = new QTimer();

        index = ui->todo_list->row(selectedItem);
        ui->start->hide();
        ui->stop->show();

        timer->start(1000);
        connect(timer, SIGNAL(timeout()), this, SLOT(ProcessTime()));
    }
}

void MainWindow::ProcessTime() {
    time_arr[index] = time_arr[index].addSecs(1);
    ui->timer_list->item(index)->setText(time_arr[index].toString());


}

void MainWindow::on_stop_clicked()
{
    delete timer;
    ui->stop->hide();
    ui->start->show();
}

