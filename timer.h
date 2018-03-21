#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QTimer>

namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = 0);
    ~Timer();

public slots:
    void timer_func();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Timer *ui;
    // integers
    int screen_width, screen_height, frame_width, frame_height;
    // QPoint for moving QWidgets
    QPoint oldPos;
    //QTimer
    QTimer *timer;
};

#endif // TIMER_H
