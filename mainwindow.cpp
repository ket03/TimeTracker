#include "mainwindow.h"
#include "ui_mainwindow.h"

// save data
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stop_timer->hide();

    connect(ui->add_elements, SIGNAL(clicked()), this, SLOT(AddElements()));
    connect(ui->task, SIGNAL(returnPressed()), this, SLOT(AddElements()));
    connect(ui->start_timer, SIGNAL(clicked()), this, SLOT(StartTimer()));
    connect(ui->stop_timer, SIGNAL(clicked()), this, SLOT(StopTimer()));
    connect(ui->delete_elements, SIGNAL(clicked()), this, SLOT(DeleteElements()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddElements()
{
    QTime time(0, 0);
    QString task = ui->task->text();
    QList<QListWidgetItem*> items = ui->todo_list->findItems(task, Qt::MatchExactly);
    if (items.isEmpty() && !task.isEmpty()) {
        ui->todo_list->addItem(task);
        ui->timer_list->addItem("00:00:00");
        time_arr.push_back(time);
        ui->task->clear();
    }
}

void MainWindow::DeleteElements() {
    QList<QListWidgetItem*> selectedItems = ui->todo_list->selectedItems();
    if (!selectedItems.isEmpty()) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Alert", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QListWidgetItem* selectedItem = selectedItems.first();
            index = ui->todo_list->row(selectedItem);
            QListWidgetItem* item = ui->timer_list->takeItem(index);
            delete item;
            qDeleteAll(ui->todo_list->selectedItems());
        }
    }
}

void MainWindow::StartTimer()
{
    QList<QListWidgetItem*> selectedItems = ui->todo_list->selectedItems();
    if (!selectedItems.isEmpty()) {
        QListWidgetItem* selectedItem = selectedItems.first();
        index = ui->todo_list->row(selectedItem);
        timer = new QTimer();

        ui->start_timer->hide();
        ui->stop_timer->show();

        timer->start(1000);
        connect(timer, SIGNAL(timeout()), this, SLOT(ProcessTime()));
    }
}

void MainWindow::ProcessTime() {
    time_arr[index] = time_arr[index].addSecs(1);
    ui->timer_list->item(index)->setText(time_arr[index].toString());
}

void MainWindow::StopTimer()
{
    delete timer;
    ui->stop_timer->hide();
    ui->start_timer->show();
}

