#include"config_dialog.hpp"


configDialog::configDialog(QWidget* parent):
    QDialog(parent)
{
    QString a = QCoreApplication::applicationFilePath();
    audioFileEditLabel = new QLabel(tr("audio file"));
    audioFileEdit = new QLineEdit();audioFileEdit->setReadOnly(true);
    audioFileEditCallPathDialogButton = new QPushButton(tr("Choice"));

    connect(audioFileEditCallPathDialogButton,SIGNAL(clicked()),this,SLOT(audioFileEditCallPathDialogButton_is_Pushed()));
//    connect(audioFileEdit,SIGNAL(textEdited(const QString&)),this,SLOT(chAudiofileEdit(const QString&)));

    QHBoxLayout *audioFileEditLayout = new QHBoxLayout();
    audioFileEditLayout->addWidget(audioFileEditLabel);
    audioFileEditLayout->addWidget(audioFileEdit);
    audioFileEditLayout->addWidget(audioFileEditCallPathDialogButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(audioFileEditLayout);

    setLayout(mainLayout);
};


void configDialog::audioFileEditCallPathDialogButton_is_Pushed(){
    audioFilePath = QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("Audio File (*)"));
    if(audioFilePath.isEmpty()){

    }else{
		/*このあたりに受け取ったオーディオファイルPATHをファイルに書きこむ処理が必要*/
        audioFileEdit->setText(audioFilePath);
        emit chAudioFile(audioFilePath);
		this->writeToFile(audioFilePath);
    }
};

/*!
 * pathでaudio fileへのPATHを受け取ってファイルに書き出す
 */
bool configDialog::writeToFile(const QString &path){
	QFile f("out.text");
	if(!f.open(QIODevice::Text | QIODevice::WriteOnly)){
		return false;
	}
	QTextStream out(&f);
	out<<path;
	return true;
};
