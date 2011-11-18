#ifndef MAINWID_HPP
#define MAINWID_HPP

#include <QtGui>
#include "countdown_setting.hpp"
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
private:
    void init_mode_Set();
    void init_buttons();

    QLabel *sl;
    QLCDNumber *one,*two,*three;
    QLCDNumber *all_s;
    QComboBox *mode_Set;
    QString current_mode_string;int current_mode;
    QPushButton *start,*stop,*pause,*config;

    countdown_setting *countdownSetting;

};

#endif // MAINWID_HPP
