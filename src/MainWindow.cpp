#include "MainWindow.hpp"
#include "xml.hpp"
#include<cstring>
#include<cstdio>

MainWindow::MainWindow()
{
	XmlParser xf;
	xf.open(config_file_path);
	xf.loadXmlData();
	enableSysTray = xf.getCheckbox(QString::fromStdString("notification"));

    real_close = false;
    w = new CentralWidget();
    connect(w,SIGNAL(change_ctd_d(const ctd_d*)),this,SLOT(changeTrayTime(const ctd_d*)));
	connect(w,SIGNAL(change_pause_f(QString)),this,SLOT(changeWindowTitle(QString)));

    sysTrayIcon = new QSystemTrayIcon(QIcon(":/photos/resource/p_icon.png"));
    sysTrayIcon->setVisible(true);//show!!
	if(enableSysTray)
		sysTrayIcon->showMessage(tr("gat2"),tr("Welcome to gat2!"),QSystemTrayIcon::Information,1500);
    connect(w,SIGNAL(finishCountDown()),this,SLOT(userCall()));


    config_editor = new PreferenceDialog();
	connect(config_editor,SIGNAL(chNotificationCheckBox(bool)),this,SLOT(changeNotificationCheckBox(bool)));
    about_widget = new gat_about_widget();

    a_about = new QAction(tr("&About"),this);
    a_about->setIcon(QIcon(":/photos/resource/p_icon_mini2.png"));
    connect(a_about,SIGNAL(triggered()),this,SLOT(about()));

    a_config = new QAction(tr("&Preferences"),this);
    connect(a_config,SIGNAL(triggered()),this,SLOT(callConfigDialog()));

    a_close = new QAction(tr("&Close"),this);
    connect(a_close,SIGNAL(triggered()),this,SLOT(closeApplication()));

    vSwitch = new QAction(tr("gat2"),this);
    connect(vSwitch,SIGNAL(triggered()),this,SLOT(changeVisible()));

    showTime = new QAction(tr("-----"),this);
    connect(showTime,SIGNAL(triggered()),this,SLOT(timeMessage()));


    help_bar = menuBar()->addMenu(tr("&gat2"));
    help_bar->addAction(a_about);
	help_bar->addAction(a_close);
    config_app = menuBar()->addMenu(tr("&Options"));
    config_app->addAction(a_config);
    sTaryIcon_Menu = new QMenu(tr("ContextMenu"));
    sTaryIcon_Menu->addAction(showTime);
    sTaryIcon_Menu->addSeparator();
    sTaryIcon_Menu->addAction(vSwitch);
    sTaryIcon_Menu->addAction(a_close);
    sysTrayIcon->setContextMenu(sTaryIcon_Menu);

    connect(this,SIGNAL(close_mainwid()),w,SLOT(delete_phonon_object()));

    setCentralWidget(w);
    setWindowTitle(tr("Gat2"));
    setWindowIcon(QIcon(":/photos/resource/p_icon.png"));
};

void MainWindow::userCall(){
	if(enableSysTray)
		sysTrayIcon->showMessage(tr("Gat2"),tr("Countdown complete."),QSystemTrayIcon::Information,5000);
};

void MainWindow::closeApplication(){
    real_close = true;
    printf("exit from gat2.\n");
    this->close();
};

void MainWindow::changeVisible(){
    setVisible(!this->isVisible());
};

void MainWindow::timeMessage(){
    QString msg;char buf[5];
    sprintf(buf,"%d",w->get_ctd_d()->get_h());
    msg += buf;

    msg += " : ";

    sprintf(buf,"%d",w->get_ctd_d()->get_m());
    msg += buf;

    msg += " : ";

    sprintf(buf,"%d",w->get_ctd_d()->get_s());
    msg += buf;
	if(enableSysTray)
		sysTrayIcon->showMessage(tr("TIME"),msg,QSystemTrayIcon::Information,5000);
};


void MainWindow::changeTrayTime(const ctd_d* data){
    QString msg;char buf[5];
    sprintf(buf,"%d",w->get_ctd_d()->get_h());
    msg += buf;

    msg += " : ";

    sprintf(buf,"%d",w->get_ctd_d()->get_m());
    msg += buf;

    msg += " : ";

    sprintf(buf,"%d",w->get_ctd_d()->get_s());
    msg += buf;
    this->showTime->setText(msg);
};

void MainWindow::changeWindowTitle(QString str){
	setWindowTitle(str);	
};

void MainWindow::about(){
    about_widget->show();
    about_widget->to_stdOut();
};

void MainWindow::callConfigDialog(){
    config_editor->show();
};

void MainWindow::changeNotificationCheckBox(bool b){
	this->enableSysTray = b;
};
