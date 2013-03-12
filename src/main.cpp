#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QSize>
#include <cstdio>
#include <cstring>
#include <string>
#include <QTextCodec>
#include "MainWindow.hpp"
#include "version.hpp"

#define default_width_size 450
#define default_height_size 250

int checkxml();

int main(int argc,char* argv[]){
    QApplication gat(argc,argv);
    gat.setApplicationName("gat2");

    for(int n = 1;n < argc;n++){
		if(strcmp(argv[n],"-v") == 0 || strcmp(argv[n],"--version") == 0){
			printf("gat2 version :: %s\n",gat_version);
			printf("See also \"About Page\".\n");
			return 0;
		}
	}

	if(checkxml() == 1){
        /*設定ファイル(xml)が生成できなかった場合の処理*/
        QMessageBox::critical((new QWidget()), "ERROR", "Application couldn't create $HOME/.gat.xml file.");
		exit(1);
	}

    QSize MainWindowSize(default_width_size,default_height_size);
    MainWindow* window = new MainWindow();
    window->setMinimumSize(MainWindowSize);
    window->show();

    return gat.exec();
}

int checkxml(){
	if(QFile::exists(config_file_path) == true) return 0;
	QFile::copy(template_xml,config_file_path);
	QFile::setPermissions(config_file_path,QFile::ReadOwner | QFile::WriteOwner | QFile::ReadUser | QFile::WriteUser);
	printf("Generate new xml config file.\n");
	if(QFile::exists(config_file_path) == true) return 0;
	else return 1;
}
