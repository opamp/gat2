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
