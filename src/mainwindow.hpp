#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "mainwid.hpp"

class mainwindow : public QMainWindow
{
public:
    mainwindow();

private:
    mainwid *w;
};

#endif // MAINWINDOW_HPP
