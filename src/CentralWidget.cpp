#include "CentralWidget.hpp"
#include "xml.hpp"
#include <iostream>
#include <config.hpp>

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
//  c_counter = new customCounter();
    countdownSetting = new SetTimerDialog(&tdata);
//  connect(c_counter,SIGNAL(finishSetting()),this,SLOT(unsetDisable()));
    connect(countdownSetting,SIGNAL(finishSetting()),this,SLOT(unsetDisable()));
    connect(&tdata,SIGNAL(changeValue(int,int,int)),this,SLOT(refLCD(int,int,int)));
    this->init_buttons();
    this->init_mode_Set();
    one = new QLCDNumber(); //h
    two = new QLCDNumber(); //m
    three = new QLCDNumber();//s
    all_s = new QLCDNumber();
    countup_msg = new EnumeratedTimeView();

    pause_f = false;

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
//  callaudio = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/audio/rsc/rsc.wav"));
    callaudio = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(""));
}

void CentralWidget::init_mode_Set(){
    mode_Set = new QComboBox();
    mode_Set->addItem(tr("Enumerate"));
    mode_Set->addItem(tr("Count Down"));
//  mode_Set->addItem(tr("Custom Counter"));
    mode_Set->setEditable(false);
    connect(mode_Set,SIGNAL(currentIndexChanged(int)),this,SLOT(mode_change(int)));
    current_mode = COUNT_UP_M;
}

void CentralWidget::init_buttons(){
    start = new QPushButton(tr("Start"));
    stop = new QPushButton(tr("Stop"));
    pause = new QPushButton(tr("Pause"));//Give way.
    config = new QPushButton(tr("Set Timer"));
    pause->setEnabled(false);
    stop->setEnabled(false);
    connect(start,SIGNAL(clicked()),this,SLOT(push_start()));
    connect(stop,SIGNAL(clicked()),this,SLOT(push_stop()));
    connect(pause,SIGNAL(clicked()),this,SLOT(push_pause()));
    connect(config,SIGNAL(clicked()),this,SLOT(push_setting()));
}

void CentralWidget::mode_change(int m){
    this->current_mode_string = mode_Set->currentText();
    this->current_mode = m;

    switch(current_mode){
    case COUNT_UP_M:
        break;
    case COUNT_DOWN_M:
        setEnabled(false);
        countdownSetting->show();
        break;
/*
    case CUSTOM_COUNT_M:
        setEnabled(false);
		c_counter->show();
        break;
*/
    }
}

void CentralWidget::push_start(){
//    delete callaudio;
    start->setEnabled(false);
    config->setEnabled(false);
    pause->setEnabled(true);
    stop->setEnabled(true);
    mode_Set->setEnabled(false);

    if(current_mode == COUNT_UP_M){
        tdata.set_h(0);
        tdata.set_m(0);
        tdata.set_s(0);
    }

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(takeOneSec()));
    t->start(1000);//1s
}

void CentralWidget::push_stop(){
    pause_f = false;
	emit change_pause_f(tr("Gat2"));
    start->setEnabled(true);
    config->setEnabled(true);
    pause->setEnabled(false);
    stop->setEnabled(false);
    mode_Set->setEnabled(true);
    this->refLCD(0,0,0);

    if(current_mode == COUNT_UP_M){
        countup_msg->setData(&tdata);
        countup_msg->show();
    }

    tdata.set_h(0);
    tdata.set_m(0);
    tdata.set_s(0);

    t->stop();
    disconnect(t,SIGNAL(timeout()),this,SLOT(takeOneSec()));
    delete t;

}

void CentralWidget::push_pause(){ //pauseボタンが押されたとき呼ばれる
    if(pause_f){//pause_f(pause_flag)がtrueならpauseしている。
        pause_f = false;
		emit change_pause_f(tr("Gat2"));
	}else{
        pause_f = true;
		emit change_pause_f(tr("Gat2 [pause]"));
	}
}

void CentralWidget::push_setting(){
    switch(current_mode){
    case COUNT_UP_M:
        break;
    case COUNT_DOWN_M:
        setEnabled(false);
        countdownSetting->show();
        break;
/*
    case CUSTOM_COUNT_M:
        break;
*/
    }
}
void CentralWidget::refLCD(int ht,int mt,int st){
    one->display(ht);
    two->display(mt);
    three->display(st);
    all_s->display(HMSToSecond(ht,mt,st));
}
void CentralWidget::takeOneSec(){
    if(pause_f)
        return;
    switch(current_mode){
    case COUNT_UP_M:
        tdata.addOneSec();
        this->refLCD(tdata.get_h(),tdata.get_m(),tdata.get_s());
        break;
    case COUNT_DOWN_M:
        if(tdata.decOneSec()){
            this->refLCD(tdata.get_h(),tdata.get_m(),tdata.get_s());
        }else{
            delete callaudio;
			if(this->readFromFile(audioFilePath) != false){
		         callaudio = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(audioFilePath));
				 callaudio->play();
			}else{
			    callaudio = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(""));
			}
            emit finishCountDown();
            this->push_stop();
        }
        break;
/*
    case CUSTOM_COUNT_M:
        break;
*/
    }
    emit change_ctd_d(&tdata);
}

bool CentralWidget::readFromFile(QString& path){
	XmlParser xf;
	if(xf.open(config_file_path) == false){
		return false;
	}
	xf.loadXmlData();
	path = xf.getAlarmFile();
	return true;
}

int HMSToSecond(const int h,const int m,const int s){
	int as = 0;
	as = s;
	as += m * 60; // to sec
	as += h * 3600; // to sec
	return as;
}


