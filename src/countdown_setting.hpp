#ifndef COUNTDOWN_SETTING_HPP
#define COUNTDOWN_SETTING_HPP
#include <QtGui>
#include "count_time_data.hpp"

class countdown_setting : public QDialog
{
Q_OBJECT
public:
    countdown_setting(ctd_d*,QWidget* parent = 0);
protected:
    void closeEvent(QCloseEvent* ce){this->push_ok();};

private slots:
    void push_ok();
    void h_change(int);
    void m_change(int);
    void s_change(int);

signals:
    void finishSetting();

private:
    ctd_d* timedata;
    QSpinBox *hb,*mb,*sb;
    QLabel *hl,*ml,*sl;

    QPushButton *ok;
};
#endif
