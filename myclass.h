#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyClass : public QThread
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);
    ~MyClass();
signals:

    // QThread interface
protected:
    void run() override;
};

#endif // MYCLASS_H
