#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "mainwid.hpp"
#include "config_dialog.hpp"
#include "AboutWidget.hpp"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow();

protected:
    void closeEvent(QCloseEvent* ce){
        //setVisible(false);
        //ce->ignore();
        emit close_mainwid();
    };

public slots:
    void userCall();
private:
    mainwid *w;
    configDialog *config_editor;
    gat_about_widget *about_widget;

    QMenu *help_bar;
    QMenu *config_app;
    QAction *a_about;
    QAction *a_config;

    QSystemTrayIcon* sysTrayIcon;
private slots:
    void about();
    void callConfigDialog();

signals:
	void close_mainwid();
};

#endif // MAINWINDOW_HPP
