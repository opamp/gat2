#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "mainwid.hpp"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow();

private:
    mainwid *w;

    QMenu *help_bar;
    QAction *a_about;
private slots:
    void about();
};

#endif // MAINWINDOW_HPP
