#include "mainwid.hpp"

mainwid::mainwid(QWidget *parent) :
    QWidget(parent)
{
    countdownSetting = new countdown_setting(&tdata);
    connect(countdownSetting,SIGNAL(finishSetting()),this,SLOT(unsetDisable()));
    connect(&tdata,SIGNAL(changeValue(int,int,int)),this,SLOT(refLCD(int,int,int)));
    this->init_buttons();
    this->init_mode_Set();
    one = new QLCDNumber(); //h
    two = new QLCDNumber(); //m
    three = new QLCDNumber();//s
    all_s = new QLCDNumber();

    QVBoxLayout *mainlayout = new QVBoxLayout();
    QHBoxLayout *sublayout = new QHBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(start);
    buttonLayout->addWidget(stop);
    buttonLayout->addWidget(pause);
    buttonLayout->addWidget(config);

    sublayout->addWidget(one);
    sublayout->addWidget(two);
    sublayout->addWidget(three);

    mainlayout->addLayout(sublayout);
    mainlayout->addWidget(all_s);
    mainlayout->addWidget(mode_Set);

    mainlayout->addLayout(buttonLayout);

    setLayout(mainlayout);
}

void mainwid::init_mode_Set(){
    mode_Set = new QComboBox();
    mode_Set->addItem(tr("Enumerate"));
    mode_Set->addItem(tr("Count Down"));
    mode_Set->addItem(tr("Custom Counter"));
    mode_Set->setEditable(false);
    connect(mode_Set,SIGNAL(currentIndexChanged(int)),this,SLOT(mode_change(int)));
}

void mainwid::init_buttons(){
    start = new QPushButton(tr("Start"));
    stop = new QPushButton(tr("Stop"));
    pause = new QPushButton(tr("Pause"));
    config = new QPushButton(tr("Setting"));
    connect(start,SIGNAL(clicked()),this,SLOT(push_start()));
    connect(stop,SIGNAL(clicked()),this,SLOT(push_stop()));
    connect(pause,SIGNAL(clicked()),this,SLOT(push_pause()));
    connect(config,SIGNAL(clicked()),this,SLOT(push_setting()));
}

void mainwid::mode_change(int m){
    this->current_mode_string = mode_Set->currentText();
    this->current_mode = m;

    switch(current_mode){
    case COUNT_UP_M:
        break;
    case COUNT_DOWN_M:
        setEnabled(false);
        countdownSetting->show();
        break;
    case CUSTOM_COUNT_M:
        break;
    }
}

void mainwid::push_start(){

}

void mainwid::push_stop(){
    this->refLCD(0,0,0);
    tdata.set_h(0);
    tdata.set_m(0);
    tdata.set_s(0);
}

void mainwid::push_pause(){

}

void mainwid::push_setting(){
    switch(current_mode){
    case COUNT_UP_M:
        break;
    case COUNT_DOWN_M:
        setEnabled(false);
        countdownSetting->show();
        break;
    case CUSTOM_COUNT_M:
        break;
    }
}
void mainwid::refLCD(int ht,int mt,int st){
    one->display(ht);
    two->display(mt);
    three->display(st);
    all_s->display(HMSToSecond(ht,mt,st));
}


int HMSToSecond(const int h,const int m,const int s){
	int as = 0;
	as = s;
	as += m * 60; // to sec
	as += h * 3600; // to sec
	return as;
}

