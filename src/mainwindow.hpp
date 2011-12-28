#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

//#include <QMainWindow>
#include <QtGui>
#include "mainwid.hpp"
#include "config_dialog.hpp"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow();

protected:
	void closeEvent(QCloseEvent* ce){
		emit close_mainwid();
	};
private:
    mainwid *w;
    configDialog* config_editor;

    QMenu *help_bar;
    QMenu *config_app;
    QAction *a_about;
    QAction *a_config;
private slots:
    void about();
    void callConfigDialog();

signals:
	void close_mainwid();
};

#endif // MAINWINDOW_HPP
