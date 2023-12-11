#ifndef SLEEP_H
#define SLEEP_H

#include <QApplication>
#include <QTime>

class Sleep
{
public:
    Sleep();
    static void sleep(int);
    static void msleep(int);
};

#endif // SLEEP_H
