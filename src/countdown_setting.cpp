#include "countdown_setting.hpp"

countdown_setting::countdown_setting(ctd_d* d,QWidget *parent):
    QDialog(parent)
{
    timedata = d;
    hb = new QSpinBox();
    mb = new QSpinBox();
    sb = new QSpinBox();

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


void countdown_setting::push_ok(){
    emit finishSetting();
    this->setVisible(false);
}
