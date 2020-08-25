#include "myclass.h"

MyClass::MyClass(QObject *parent) : QThread(parent)
{
    qInfo() << this << "Created on" << QThread::currentThread();
}

MyClass::~MyClass()
{
    qInfo() << this << "Destoyed on" << QThread::currentThread();
}

void MyClass::run()
{
    qInfo() << this << "Run on" << QThread::currentThread();

    //Do thread stuff here
    QThread::currentThread()->msleep(5000);

    qInfo() << this << "Finished on" << QThread::currentThread();
}
