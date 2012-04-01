#include "mainwindow.hpp"

mainwindow::mainwindow()
{
    w = new mainwid();

    sysTrayIcon = new QSystemTrayIcon(QIcon(":/photos/resource/p_icon.png"));
    sysTrayIcon->setVisible(true);//show!!
    sysTrayIcon->showMessage(tr("gat2"),tr("Welcome to gat2!"),QSystemTrayIcon::Information,1500);

    connect(w,SIGNAL(finishCountDown()),this,SLOT(userCall()));


    config_editor = new configDialog();
    about_widget = new gat_about_widget();

    a_about = new QAction(tr("&About"),this);
    a_about->setIcon(QIcon(":/photos/resource/p_icon_mini2.png"));
    connect(a_about,SIGNAL(triggered()),this,SLOT(about()));

    a_config = new QAction(tr("&Preferences"),this);
    connect(a_config,SIGNAL(triggered()),this,SLOT(callConfigDialog()));

    help_bar = menuBar()->addMenu(tr("&Help and Info"));
    help_bar->addAction(a_about);
    config_app = menuBar()->addMenu(tr("&Config"));
    config_app->addAction(a_config); // configウィンドウにフリーズするバグあり(Windows Only?)


    connect(this,SIGNAL(close_mainwid()),w,SLOT(delete_phonon_object()));

    setCentralWidget(w);
    setWindowTitle(tr("Gat2"));
//    setWindowIcon(QIcon(":/photos/resource/p_icon_mini2.png"));
    setWindowIcon(QIcon(":/photos/resource/p_icon.png"));
};

void mainwindow::userCall(){
    sysTrayIcon->showMessage(tr("Gat2"),tr("Countdown is finished."),QSystemTrayIcon::Information,5000);
};

void mainwindow::about(){
    about_widget->show();
    about_widget->to_stdOut();
};

void mainwindow::callConfigDialog(){
    config_editor->show();
};
