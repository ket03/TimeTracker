#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);

    w.setPalette(palette);
    w.setWindowTitle("Time Tracker");
    w.show();

    return a.exec();
}
