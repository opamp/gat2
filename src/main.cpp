#include <QApplication>
#include <QFile>
#include <QDir>
#include <QSize>
#include <cstdio>
#include <cstring>
#include <string>
#include "mainwindow.hpp"
#include "version.hpp"

#define default_width_size 450
#define default_height_size 250

int checkxml();

int main(int argc,char* argv[]){
	for(int n = 1;n < argc;n++){
		if(strcmp(argv[n],"-v") == 0 || strcmp(argv[n],"--version") == 0){
			printf("gat2 version :: %s\n",gat_version);
			printf("See also \"About Page\".\n");
			return 0;
		}
	}
	printf("start gat2.\n");
	
	checkxml();

    QApplication gat(argc,argv);
	gat.setApplicationName("gat2");

	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	QSize mainwindow_size(default_width_size,default_height_size);
    mainwindow* window = new mainwindow();
	window->setMinimumSize(mainwindow_size);
//	window->setMaximumSize(mainwindow_size); // If this line is enable,you cannot change WindowSize.
    window->show();

    return gat.exec();
}

int checkxml(){
	QFile file(config_file_path);
	if(file.exists() == true) return 0;


}
