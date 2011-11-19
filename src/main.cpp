#include<QApplication>
#include"mainwindow.hpp"


int main(int argc,char* argv[]){
    QApplication gat(argc,argv);

    mainwindow* window = new mainwindow();
    window->show();

    return gat.exec();
}
