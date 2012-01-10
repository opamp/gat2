#include <QApplication>
#include <QSize>
#include "mainwindow.hpp"

#define default_width_size 450
#define default_height_size 250

int main(int argc,char* argv[]){
    QApplication gat(argc,argv);
	gat.setApplicationName("gat2");

	QSize mainwindow_size(default_width_size,default_height_size);
    mainwindow* window = new mainwindow();
	window->setMinimumSize(mainwindow_size);
//	window->setMaximumSize(mainwindow_size); // If this line is enable,you cannot change WindowSize.
    window->show();

    return gat.exec();
}
