#include "timer.hpp"

timer::timer()
{
    c = -1;
    stop_f = false;
}

void timer::run(){
    while(stop_f == false)
    {
        wait(1000);
        c+=1;
        emit oneSec(this->c);
    }
}
