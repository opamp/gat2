#include"config_dialog.hpp"
#include"xml.hpp"
#include <iostream>


configDialog::configDialog(QWidget* parent):
    QDialog(parent)
{
    audioFileEdit = new QLineEdit();audioFileEdit->setReadOnly(true);
    QString saveDir = QDir::homePath();
    saveDir += "/.gat2.conf";
    QFile file(saveDir);
    if(!file.open(QIODevice::Text | QIODevice::ReadOnly)){
        file.close();
    }else{
        QTextStream in(&file);
        QString path = in.readLine();
        audioFileEdit->setText(path);
        file.close();
    }

    QString a = QCoreApplication::applicationFilePath();
    audioFileEditLabel = new QLabel(tr("audio file"));
    audioFileEditCallPathDialogButton = new QPushButton(tr("Choice"));

    connect(audioFileEditCallPathDialogButton,SIGNAL(clicked()),this,SLOT(audioFileEditCallPathDialogButton_is_Pushed()));

	notificationCheck = new QCheckBox("Notification");
	connect(notificationCheck,SIGNAL(stateChanged(int)),this,SLOT(notificationCheckChanged(int)));


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


void configDialog::audioFileEditCallPathDialogButton_is_Pushed(){
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
bool configDialog::writeToFile(const QString &path){
	/*old
    QString saveDir = QDir::homePath();
    saveDir += "/.gat2.conf";
    QFile f(saveDir);
    if(!f.open(QIODevice::Text | QIODevice::WriteOnly)){
		return false; // 失敗
	}
	QTextStream out(&f);
	out<<path;
	return true; //成功
	*/

	XmlParser xf;
	if(xf.open(config_file_path) == false){
		std::cout<<"fail to save xml"<<std::endl;
		return false;
	}
	xf.setAlarmFile(path);
	xf.save();
	xf.close();
	return true;
};

void configDialog::notificationCheckChanged(int n){
	std::cout<<"notification check box is changed.["<<n<<"]"<<std::endl;
}
