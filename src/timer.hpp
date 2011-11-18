#ifndef TIMER_HPP
#define TIMER_HPP
#include <QtGui>
#include <QThread>

class timer : public QThread
{
Q_OBJECT
public:
    timer();
    void startThread(){this->run();};
    bool stop_f; // this thread stop when this flag is true.

protected:
    void run();

private:
    int c;

signals:
    void oneSec(int);
};

#endif // TIMER_HPP
