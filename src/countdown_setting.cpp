#include "countdown_setting.hpp"

countdown_setting::countdown_setting(ctd_d* d,QWidget *parent):
    QDialog(parent)
{
    timedata = d;
    timedata->set_h(0);
    timedata->set_m(0);
    timedata->set_s(0);
    hb = new QSpinBox();hb->setMinimum(0);
    mb = new QSpinBox();mb->setMinimum(0);
    sb = new QSpinBox();sb->setMinimum(0);
    sb->setValue(timedata->get_s());
    mb->setValue(timedata->get_m());
    hb->setValue(timedata->get_h());
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
    timedata->set_h(h);
}

void countdown_setting::m_change(int m){
    if(m >= 60){
        timedata->set_m(0);
        timedata->set_h(timedata->get_h() + 1);
        hb->setValue(timedata->get_h());
        mb->setValue(timedata->get_m());
    }else{
        timedata->set_m(m);
    }
}

void countdown_setting::s_change(int s){
    if(s >= 60){
        timedata->set_s(0);
        timedata->set_m(timedata->get_m() + 1);
        mb->setValue(timedata->get_m());
        sb->setValue(timedata->get_s());
    }else{
        timedata->set_s(s);
    }
}

void countdown_setting::push_ok(){
    emit finishSetting();
    this->setVisible(false);
}

// Update the values automatically.
void countdown_setting::show() {
    sb->setValue(timedata->get_s());
    mb->setValue(timedata->get_m());
    hb->setValue(timedata->get_h());

    // Continue the call to the parent class.
    QDialog::show();
}
