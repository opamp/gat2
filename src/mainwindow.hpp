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
        if(real_close == false){
            setVisible(false);
            ce->ignore();
        }else{
            emit close_mainwid();
            ce->accept();
        }
    };

public slots:
    void userCall();
    void closeApplication();
    void changeVisible();
    void timeMessage();
private:
    bool real_close;
    mainwid *w;
    configDialog *config_editor;
    gat_about_widget *about_widget;

    QMenu *help_bar;
    QMenu *config_app;
    QAction *a_about;
    QAction *a_config;
    QAction *a_close;

    QSystemTrayIcon *sysTrayIcon;
    QMenu *sTaryIcon_Menu;
    QAction *vSwitch;
    QAction *showTime;
private slots:
    void about();
    void callConfigDialog();
    void changeTrayTime(const ctd_d*);

signals:
	void close_mainwid();
};

#endif // MAINWINDOW_HPP
