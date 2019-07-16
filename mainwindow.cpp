
#include "mainwindow.h"
#include "model.h"
#include "container1.h"
#include "widget.h"
#include "add.h"
#include "ricette.h"
#include "cercawidget.h"
#include "cercawidgetresult.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include<QMainWindow>
#include<QToolBar>
#include<QWidget>
#include<QMessageBox>
#include <QGroupBox>
#include <QGridLayout>
#include <QTableWidget>
#include<QTableWidgetItem>
#include <QFileDialog>
#include <QPushButton>
#include <QScrollArea>


mainwindow::mainwindow(QWidget* parent):
    QMainWindow(parent),
    m(new Model),
    centralGroupBox(new QVBoxLayout)



{   setWindowTitle(tr("Il mio ricettario")); //titolo applicazione
    setFixedSize(QSize(450, 650)); //dimensione fissa non ridimensionabile

    // Creo il menu
    QMenu *menu = new QMenu("File");
    menuBar()->addMenu(menu);
    QAction *save = new QAction("Save");
    QAction *load = new QAction("Load");
    QAction *exit = new QAction("Exit");
    menu->addAction(save);
    menu->addAction(load);
    menu->addAction(exit);

     connect(exit, SIGNAL(triggered()),
             this, SLOT(close()));


     connect(save, SIGNAL(triggered()),
             this, SLOT(save()));

     connect(load, SIGNAL(triggered()),
             this, SLOT(load()));

     //creo una tool bar
    QToolBar *toolbar= new QToolBar();
    QAction *add = new QAction("Aggiungi");

    //QAction *del = new QAction("Elimina");
    QAction *cer = new QAction("Cerca");
    toolbar->addAction(add);

    //toolbar->addAction(del);
    toolbar->addAction(cer);
    addToolBar(toolbar);

    connect(add, SIGNAL(triggered()),
            this, SLOT(addOrder()));
    //connect(add, &QAction::triggered, this, &mainwindow::addOrder);

   connect(cer, SIGNAL(triggered()),
            this, SLOT(cercaR()));




    //setWindowIcon(QIcon(":/file.svg")); // icona del programma

        //zona centrale
    QScrollArea *scroll= new QScrollArea;
    QWidget *widget = new QWidget;
    centralGroupBox->setSizeConstraint(QLayout::SetMinAndMaxSize);
    widget->setLayout((centralGroupBox));
    scroll->setWidget(widget);
    scroll->setWidgetResizable(false);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(scroll);



}



QSize mainwindow::sizeHint() const {
    return QSize(500, 600);
}

void mainwindow::addOrder()
{
    add agg;
    agg.exec();
    widget *r=new widget(m->addO(
                             agg.getType(),
                             agg.getNome(),
                             agg.getPrezzo(),
                             agg.getCottura(),
                             agg.getTipo()
                             )
                    );

    centralGroupBox->addWidget(r);

        //SEGNALE PER LA RIMOZIONE DI UNA RICETTA
    connect(r, &widget::remove, this, &mainwindow::removeR);

}

void mainwindow::removeR(widget *o)
{
    centralGroupBox->removeWidget(o);
    ricette* a=o->getRicetta();
    m->remove(a);
    delete o;
}

void mainwindow::cercaR()
{
    cercaWidget c;
    c.exec();
}






void mainwindow::save()
{
    m->save();

}
void mainwindow::load()
{

    QFileDialog choose;
    choose.setFileMode(QFileDialog::ExistingFile);
    choose.setOption(QFileDialog::DontConfirmOverwrite);
    choose.setOption(QFileDialog::ReadOnly);

    choose.setWindowTitle("Load");
    choose.setNameFilter("XML file (*.xml)");

    if(choose.exec())
        m->load(choose.selectedFiles()[0]);


}







