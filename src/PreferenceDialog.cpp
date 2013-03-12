#include "PreferenceDialog.hpp"
#include "xml.hpp"
#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>


PreferenceDialog::PreferenceDialog(QWidget* parent):
    QDialog(parent)
{
    audioFileEdit = new QLineEdit();audioFileEdit->setReadOnly(true);
	
	notificationCheck = new QCheckBox("Notification");
	connect(notificationCheck,SIGNAL(stateChanged(int)),this,SLOT(notificationCheckChanged(int)));
	
		/*xml read*/	
	XmlParser xf;
	xf.open(config_file_path);
	xf.loadXmlData();
	audioFileEdit->setText(xf.getAlarmFile());

	if(xf.getCheckbox(QString::fromStdString("notification")) == true){
		notificationCheck->setChecked(true);
	}else{
		notificationCheck->setChecked(false);
	}
		/*--------*/

    QString a = QCoreApplication::applicationFilePath();
    audioFileEditLabel = new QLabel(tr("audio file"));
    audioFileEditCallPathDialogButton = new QPushButton(tr("Choice"));

    connect(audioFileEditCallPathDialogButton,SIGNAL(clicked()),this,SLOT(audioFileEditCallPathDialogButton_is_Pushed()));



    QHBoxLayout *audioFileEditLayout = new QHBoxLayout();
    audioFileEditLayout->addWidget(audioFileEditLabel);
    audioFileEditLayout->addWidget(audioFileEdit);
    audioFileEditLayout->addWidget(audioFileEditCallPathDialogButton);

	QVBoxLayout *checkboxes = new QVBoxLayout();
	checkboxes->addWidget(notificationCheck);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(audioFileEditLayout);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(checkboxes);

    setLayout(mainLayout);
};


void PreferenceDialog::audioFileEditCallPathDialogButton_is_Pushed(){
    audioFilePath = QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("Audio File (*)"));
	std::cout<<audioFilePath.toStdString()<<std::endl;
    if(audioFilePath.isEmpty()){

    }else{
        audioFileEdit->setText(audioFilePath);
        emit chAudioFile(audioFilePath);
        this->writeToFile(audioFilePath);
    }
};

/*!
 * pathでaudio fileへのPATHを受け取ってファイルに書き出す
 */
bool PreferenceDialog::writeToFile(const QString &path){
	XmlParser xf;
	if(xf.open(config_file_path) == false){
		std::cout<<"Failed to save xml"<<std::endl;
		return false;
	}
	xf.loadXmlData();
	xf.setAlarmFile(path);
	xf.save();
	return true;
};

void PreferenceDialog::notificationCheckChanged(int n){
	QString s = "notification";
	std::cout<<"Notification check box changed.["<<n<<"]"<<std::endl;
	XmlParser xf;
	if(xf.open(config_file_path) == false){
		std::cout<<"Failed to save xml"<<std::endl;
		return;
	}
	xf.loadXmlData();
	if(n == 0){
		xf.setCheckbox(s,false);
		emit chNotificationCheckBox(false);
	}else{
		xf.setCheckbox(s,true);
		emit chNotificationCheckBox(true);
	}
	xf.save();
}
