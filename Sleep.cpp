#include "Sleep.h"

Sleep::Sleep() {}

void Sleep::sleep(int second)
{
    QTime target = QTime::currentTime().addSecs(second);

    while (QTime::currentTime() < target)
        QApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Sleep::msleep(int ms)
{
    QTime target = QTime::currentTime().addMSecs(ms);

    while (QTime::currentTime() < target)
        QApplication::processEvents(QEventLoop::AllEvents, 5);
}
