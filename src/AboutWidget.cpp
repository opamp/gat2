#include "AboutWidget.hpp"
#include "version.hpp"
#include <iostream>

gat_about_widget::gat_about_widget(QWidget* parent):
	QWidget(parent)
{
    QString v = gat_version;
    licenseView = new QTextEdit();
    QFile lFile(":/text/resource/text/LICENSE");
    if(!lFile.open(QFile::Text | QFile::ReadOnly)){
        licenseView->setPlainText("Failed to read text.");
    }else{
        QTextStream op(&lFile);
        licenseView->setPlainText(op.readAll());

        lFile.close();
        licenseView->setReadOnly(true);
    }
    QString versioninfo_str = "<h2>Version ::" + v + "</h2>";

    closeButton = new QPushButton(tr("OK"));

    appName = new QLabel(tr("<h1>gat2 - A Simple Timer - </h1>"));
    versionInfo = new QLabel(versioninfo_str);
    repoUrl = new QLabel(tr("https://github.com/opamp/gat2"));

    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(appName);
    mainLayout->addWidget(versionInfo);
    mainLayout->addWidget(repoUrl);
    mainLayout->addWidget(licenseView);
    mainLayout->addWidget(closeButton);

    setLayout(mainLayout);
    setWindowIcon(QIcon(":/photos/resource/p_icon_mini.png"));
    setWindowTitle(tr("About gat2"));
};

void gat_about_widget::to_stdOut(){
    using namespace std;
    cout<<"Gat2 - A Simple Timer"<<endl<<
          "version :: "<<gat_version<<endl<<endl;
    cout<<"Source Code : https://github.com/opamp/gat2"<<endl<<
          "You can clone the gat2 repository with:"<<endl<<
          "  -> \"git clone git://github.com/opamp/gat2.git\""<<endl<<endl;
    cout<<licenseView->toPlainText().toStdString()<<endl;
};


