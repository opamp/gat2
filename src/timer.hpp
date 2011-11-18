#ifndef TIMER_HPP
#define TIMER_HPP
#include <QtGui>
#include <QThread>

class timer : public QThread
{
public:
    timer();

protected:
    void run();
};

#endif // TIMER_HPP
