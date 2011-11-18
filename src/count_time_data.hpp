#ifndef COUNT_TIME_DATA_HPP
#define COUNT_TIME_DATA_HPP
#include <cstdio>
#include <QObject>
/*
struct count_time_data{
    int h;
    int m;
    int s;
};

typedef struct count_time_data ctd_d;
*/
class ctd_d : public QObject{
Q_OBJECT
public:
    ctd_d();
    void set_h(int);
    void set_m(int);
    void set_s(int);
    int get_h();
    int get_m();
    int get_s();
    bool isZero();
    void addOneSec();
    bool decOneSec();
signals:
    void changeValue(int,int,int);
protected:
    int h;
    int m;
    int s;
};

#endif
