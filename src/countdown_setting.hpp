#ifndef COUNTDOWN_SETTING_HPP
#define COUNTDOWN_SETTING_HPP
#include <QtGui>

class countdown_setting : public QDialog
{
Q_OBJECT
public:
    countdown_setting(QWidget* parent = 0);

private:
    int h,m,s;
    int as;

    QSpinBox *hb,*mb,*sb;
    QLabel *hl,*ml,*sl;

    QPushButton *ok;
};
#endif
