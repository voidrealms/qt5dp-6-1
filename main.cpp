#include <QCoreApplication>

/*

  What
  Inheriting QThread

  Description
  Not the best idea but it can be done

  Why
  Java style threads
  Note - This is not the best way!!!
  You can easily break the thread

  Example
  Inherit QThread
   https://doc.qt.io/qt-5/qthread.html

 */

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QSharedPointer>
#include "myclass.h"

MyClass *thread;
QTimer *timer;

void timeout()
{
    if(thread) return;
    if(timer) return;

    if(thread->isRunning() == true && thread->isFinished() == false)
    {
        qInfo() << "Thread is running!";
    }

    if(thread->isRunning() == false && thread->isFinished() == true)
    {
        qInfo() << "Thread is finished!";
        timer->stop();
        thread->deleteLater();
        timer->deleteLater();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread = new MyClass(&a);
    timer = new QTimer(&a);
    thread->setObjectName("Child Thread");

    timer->setInterval(1000);
    QObject::connect(timer, &QTimer::timeout, timeout);
    timer->start();
    thread->start(); //QThread::start calls QThread::run()

    //Do other things in the background


    return a.exec();
}




