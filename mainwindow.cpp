#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "timer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image(":/src/img/src/img/back_pic.jpg");
    ui->label_pic->setPixmap(image);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //Button pressed -> Start the timer
{
    this->hide(); // hide main window

    // start timer window
    Timer timer_window;
    timer_window.setModal(true);
    timer_window.exec();
}
