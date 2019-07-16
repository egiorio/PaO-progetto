#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication pao(argc, argv);
    mainwindow w;
    w.show();
    return pao.exec();
}


/*installasre astyle beautifier*/
