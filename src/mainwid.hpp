#ifndef MAINWID_HPP
#define MAINWID_HPP

#include <QtGui>
/*
必要なボタンは 一時停止(再開) 中止 開始 かぬ あと 予約 か

*/

class mainwid : public QWidget
{
    Q_OBJECT
public:
    explicit mainwid(QWidget *parent = 0);
    
signals:
    
public slots:

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
};

#endif // MAINWID_HPP
