#ifndef MAINWID_HPP
#define MAINWID_HPP

#include <QtGui>
#include "countdown_setting.hpp"
#include "count_time_data.hpp"
#include "timer.hpp"

/*
必要なボタンは 一時停止(再開) 中止 開始 かぬ あと 予約 か
*/

#define COUNT_UP_M 0
#define COUNT_DOWN_M 1
#define CUSTOM_COUNT_M 2

class mainwid : public QWidget
{
    Q_OBJECT
public:
    explicit mainwid(QWidget *parent = 0);
    
signals:
    
public slots:
    void unsetDisable(){
        setEnabled(true);
    };
private slots:
    void mode_change(int);
    void refLCD(int,int,int);
    void push_start();
    void push_stop();
    void push_setting();
    void push_pause();
private:
    void init_mode_Set();
    void init_buttons();

    QLabel *sl;
    QLCDNumber *one,*two,*three;
    QLCDNumber *all_s;
    QComboBox *mode_Set;
    QString current_mode_string;int current_mode;
    QPushButton *start,*stop,*pause,*config;
    ctd_d tdata;

    countdown_setting *countdownSetting;

};

int HMSToSecond(const int,const int,const int);

#endif // MAINWID_HPP
