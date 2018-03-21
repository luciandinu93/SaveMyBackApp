#include "timer.h"
#include "ui_timer.h"
#include <QMessageBox>

Timer::Timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timer_func()));

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint); // frameless and always on top

    timer->start(1000);

    //Get screen coordinates
    QRect screen = QApplication::desktop()->screenGeometry();
    screen_height = screen.height();
    screen_width = screen.width();
    //Get timer's frame coordinates
    QRect frame = frameGeometry();
    frame_height = frame.height();
    frame_width = frame.width();

    //For debugging purpose
    qDebug() << "screen_heigth = " << screen_height << " and " <<
                " screen_width = " << screen_width << " test frame height and width" <<
                frame_height << " , " << frame_width << endl;

    //Move the window to bottom right
    this->move(screen_width - frame_width, screen_height - frame_height);
    QPoint qp = this->mapToGlobal(QPoint(0,0));
    qDebug() << "pos of window is x = " << qp.x() << "and y = " << qp.y() << endl;

}

Timer::~Timer()
{
    delete ui;
}

void Timer::timer_func()
{
//    timer_counter++;
//    if(timer_counter > 10) {
//        timer_counter = 0;
//        qDebug() << "test...";
//    }
//    ui->progressBar->setValue(timer_counter*10);
    //QMessageBox::information(this, "One hour passed", "One hour passed, just take a break");
}

void Timer::mousePressEvent(QMouseEvent *event)
{
    //Save the global (screen-coordinate) position of where the mouse was
    oldPos = event->globalPos();
}

void Timer::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint delta = event->globalPos() - oldPos; // Calculate relative difference
    move(x() + delta.x(), y() + delta.y()); // Position the Frame to mouse location
    oldPos = event->globalPos(); // oldPos update
}

