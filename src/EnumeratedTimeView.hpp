#ifndef COUNTUP_BOX_HPP
#define COUNTUP_BOX_HPP
#include <QtGui>
#include "TimeData.hpp"

class EnumeratedTimeView : public QDialog{
Q_OBJECT
public:
    EnumeratedTimeView(QWidget* parent = 0);
    void setData(ctd_d*);

private:
    QLabel *MainLabel;
    QPushButton *OKButton;
};
#endif
