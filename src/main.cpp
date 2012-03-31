#include <QApplication>
#include <QSize>
#include <cstdio>
#include <cstring>
#include "mainwindow.hpp"
#include "version.hpp"

#define default_width_size 450
#define default_height_size 250

int main(int argc,char* argv[]){
	for(int n = 1;n < argc;n++){
		if(strcmp(argv[n],"-v") == 0 || strcmp(argv[n],"--version") == 0){
			printf("gat2 version :: %s\n",gat_version);
			printf("See also \"About Page\".\n");
			return 0;
		}
	}
	printf("start gat2.\n");
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
