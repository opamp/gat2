#include "mainwindow.hpp"

mainwindow::mainwindow()
{
    w = new mainwid();
    config_editor = new configDialog();

    a_about = new QAction(tr("&About"),this);
    a_about->setIcon(QIcon(":/photos/resource/p_icon_mini2.png"));
    connect(a_about,SIGNAL(triggered()),this,SLOT(about()));

    a_config = new QAction(tr("&Preferences"),this);
    connect(a_config,SIGNAL(triggered()),this,SLOT(callConfigDialog()));

    help_bar = menuBar()->addMenu(tr("&Help and Info"));
    help_bar->addAction(a_about);
    config_app = menuBar()->addMenu(tr("&Config"));
    config_app->addAction(a_config);


	connect(this,SIGNAL(close_mainwid()),w,SLOT(delete_phonon_object()));

    setCentralWidget(w);
    setWindowTitle(tr("Gat2"));
//    setWindowIcon(QIcon(":/photos/resource/p_icon_mini2.png"));
    setWindowIcon(QIcon(":/photos/resource/p_icon.png"));
};

void mainwindow::about(){
    QMessageBox::about(this,tr("About Gat2"),
            tr("<h2>Gat2</h2>"
               "<p>Copyright (c) 2011 opamp"
               "<p>version:: 2.2.1")); // version
};

void mainwindow::callConfigDialog(){
    config_editor->show();
};
