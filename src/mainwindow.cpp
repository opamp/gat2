#include "mainwindow.hpp"

mainwindow::mainwindow()
{
    w = new mainwid();


    setCentralWidget(w);
    setWindowTitle(tr("Gat2"));
}
