#ifndef COUNTDOWN_SETTING_HPP
#define COUNTDOWN_SETTING_HPP
#include <QtGui>
#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include "TimeData.hpp"

class SetTimerDialog : public QDialog
{
Q_OBJECT
public:
    SetTimerDialog(ctd_d*,QWidget* parent = 0);
    void show();

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

    int orig_s;
    int orig_m;
    int orig_h;
};
#endif
