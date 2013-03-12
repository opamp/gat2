#ifndef ABOUT_WIDGET_HPP
#define ABOUT_WIDGET_HPP
#include <QtGui>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class gat_about_widget : public QWidget
{
Q_OBJECT
public:
	gat_about_widget(QWidget* parent = 0);
    void to_stdOut();
private:
    QPushButton *closeButton;

    QLabel *appName;
    QLabel *versionInfo;
    QLabel *repoUrl;

    QTextEdit* licenseView;
};
#endif
