#ifndef COUNTUP_BOX_HPP
#define COUNTUP_BOX_HPP
#include <QtGui>
#include "count_time_data.hpp"

class countup_box : public QDialog{
Q_OBJECT
public:
    countup_box(QWidget* parent = 0);
    void setData(ctd_d*);

private:
    QLabel *p;
    QPushButton *b;
};
#endif
