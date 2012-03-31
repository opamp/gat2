#include "customCounter.hpp"


customCounter::customCounter(QWidget *parent):
	QWidget(parent)
{
	/*未実装をユーザーに教えるための一時的な手段としてQLabelを使う*/
	msg_l = new QLabel("This implementation isn't done.");
	/*------------------------------------------------------------*/
	ok = new QPushButton(tr("OK"));

	connect(ok,SIGNAL(clicked()),this,SLOT(push_ok()));

	QHBoxLayout *mainlayout = new QHBoxLayout();
	mainlayout->addWidget(msg_l);// これも一時的な配置
	mainlayout->addWidget(ok);

	setLayout(mainlayout);
};


void customCounter::push_ok(){
	emit finishSetting();
	this->setVisible(false);
}
