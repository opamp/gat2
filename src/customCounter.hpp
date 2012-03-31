#ifndef CUSTOM_COUNTER_HPP
#define CUSTOM_COUNTER_HPP
#include <QtGui>


class customCounter : public QWidget
{
Q_OBJECT
public:
	customCounter(QWidget* parent = 0);

private slots:
	void push_ok();

signals:
	void finishSetting();

private:
	QLabel *msg_l;
	QPushButton* ok;
};
#endif
