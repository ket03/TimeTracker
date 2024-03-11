#include "mainwindow.h"
#include "ui_mainwindow.h"

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


// при удачном добавлении элемента в первый список - добавить время во второй список
// убрать его видимость
// наслоить на него лейбл который будет отображать его данные
void MainWindow::add_elements()
{
    QString task = ui->task->text();
    QList<QListWidgetItem*> items = ui->todo_list->findItems(task, Qt::MatchExactly);
    if (items.isEmpty() && !task.isEmpty()) {
        ui->todo_list->addItem(task);
    }

}

void MainWindow::startTimeEdit()
{
    ui->start->hide();
    ui->stop->show();

    timer = new QTimer();
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(ProcessTime()));
}

void MainWindow::ProcessTime() {
    QTime current = ui->timeEdit->time().addSecs(1);
    ui->timeEdit->setTime(current);

}

void MainWindow::on_stop_clicked()
{
    delete timer;
    ui->stop->hide();
    ui->start->show();
}

