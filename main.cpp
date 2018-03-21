#include "mainwindow.h"
#include "timer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Main windows dimensions variables
    //int mainwindow_width = 600;
    //int mainwindow_heigth = 350;

    QApplication a(argc, argv);
    //MainWindow w;
    //w.setFixedSize(mainwindow_width,mainwindow_heigth); //Setting fixed size to the window
    Timer w;
    w.show();

    return a.exec(); // Application is starting
}
