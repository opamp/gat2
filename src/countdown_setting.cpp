#include "countdown_setting.hpp"

countdown_setting::countdown_setting(ctd_d* d,QWidget *parent):
    QDialog(parent)
{
    timedata = d;
    timedata->h = 0;
    timedata->m = 0;
    timedata->s = 1;
    hb = new QSpinBox();hb->setMinimum(0);
    mb = new QSpinBox();mb->setMinimum(0);
    sb = new QSpinBox();sb->setMinimum(0);
    sb->setValue(timedata->s);
    mb->setValue(timedata->m);
    hb->setValue(timedata->h);
    connect(hb,SIGNAL(valueChanged(int)),this,SLOT(h_change(int)));
    connect(mb,SIGNAL(valueChanged(int)),this,SLOT(m_change(int)));
    connect(sb,SIGNAL(valueChanged(int)),this,SLOT(s_change(int)));

    hl = new QLabel(tr("h"));
    ml = new QLabel(tr("m"));
    sl = new QLabel(tr("s"));

    ok = new QPushButton(tr("OK"));
    connect(ok,SIGNAL(clicked()),this,SLOT(push_ok()));

    QHBoxLayout *mainSpinBoxlayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainSpinBoxlayout->addWidget(hb);
    mainSpinBoxlayout->addWidget(hl);
    mainSpinBoxlayout->addWidget(mb);
    mainSpinBoxlayout->addWidget(ml);
    mainSpinBoxlayout->addWidget(sb);
    mainSpinBoxlayout->addWidget(sl);

    mainLayout->addLayout(mainSpinBoxlayout);
    mainLayout->addWidget(ok);

    setLayout(mainLayout);
}

void countdown_setting::h_change(int h){
    timedata->h = h;
}
void countdown_setting::m_change(int m){
    if(m >= 60){
        timedata->m = 0;
        timedata->h += 1;
        hb->setValue(timedata->h);
        mb->setValue(timedata->m);
    }else{
        timedata->m = m;
    }
}
void countdown_setting::s_change(int s){
    if(s >= 60){
        timedata->s = 0;
        timedata->m += 1;
        mb->setValue(timedata->m);
        sb->setValue(timedata->s);
    }else{
        timedata->s = s;
    }
}



void countdown_setting::push_ok(){
    emit finishSetting();
    this->setVisible(false);
}
