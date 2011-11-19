#include "count_time_data.hpp"

ctd_d::ctd_d(){
    h = m = s = 0;
}

 void ctd_d::set_h(int h)
 {
    if(h < 0){
        return;
    }else{
        this->h = h;
        emit changeValue(this->h,this->m,this->s);
    }
 }
 void ctd_d::set_m(int m)
 {
    if(m < 0){
        return;
    }else{
        this->m = m;
        emit changeValue(this->h,this->m,this->s);
    }

 }
 void ctd_d::set_s(int s)
 {
    if(s < 0){
        return;
    }else{
        this->s = s;
        emit changeValue(this->h,this->m,this->s);
    }
 }
 int ctd_d::get_h()
 {
    return this->h;
 }
 int ctd_d::get_m()
 {
    return this->m;
 }
 int ctd_d::get_s()
 {
    return this->s;
 }
bool ctd_d::isZero(){
    if(s == 0 && m == 0 && h == 0){
        return true;
    }else{
        return false;
    }
}

void ctd_d::addOneSec(){
    s+=1;
    if(s >= 60){
        s = 0;
        m += 1;
        if(m >= 60){
            m = 0;
            h += 1;
        }
    }
}

bool ctd_d::decOneSec(){
    if(this->isZero() == true){
        return false;
    }
    s-=1;
    if(s < 0){
        m-=1;
        s = 59;
        if(m < 0){
            h-=1;
            m = 59;
        }
    }
    return true;
}
