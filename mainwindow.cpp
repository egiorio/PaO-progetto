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

    QAction *add = new QAction("Aggiungi"); //pulsante per aggiungere una ricetta


    QAction *cer = new QAction("Cerca"); //pulsante per cercare una ricetta
    toolbar->addAction(add);


    toolbar->addAction(cer);
    addToolBar(toolbar);

    //connect per aggiungi e cerca
    connect(add, SIGNAL(triggered()),
            this, SLOT(addOrder()));


   connect(cer, SIGNAL(triggered()),
            this, SLOT(cercaR()));






    //setWindowIcon(QIcon(":/file.svg")); // icona del programma

    //zona centrale

   //scrool verticale
    QScrollArea *scroll= new QScrollArea;
    QWidget *widget = new QWidget;
    centralGroupBox->setSizeConstraint(QLayout::SetMinAndMaxSize);
    widget->setLayout((centralGroupBox));
    scroll->setWidget(widget);
    scroll->setWidgetResizable(false);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(scroll);

    //connect per la load
    connect(this, SIGNAL(ChangeR()), this, SLOT(update()));



}



QSize mainwindow::sizeHint() const {
    return QSize(500, 600);
}

void mainwindow::addOrder()
{ //funzione che aggiunge una ricetta alla gui. crea un oggetto di tipo agg, controlla se l'oggetto esiste, si SI crea il widget che ha anche la possibilità di essere rimosso
    add agg;
    agg.exec();
    if(agg.getNome() != "" && agg.getPrezzo() != 0 && (agg.getTipo() == "Carne" ||agg.getTipo() == "Pesce") ||
                                                        agg.getTipo() == "Vegetariana" || agg.getTipo() == "Onnivora" ||
                                                        agg.getTipo() == "Vegana" || agg.getTipo() == "non vegana"){
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



}

void mainwindow::removeR(widget *o) //rimozione del widget e dal contenitore dell'ogg o
{
    centralGroupBox->removeWidget(o);
    ricette* a=o->getRicetta();
    m->remove(a);
    delete o;
}

void mainwindow::cercaR() //slot per la ricerca di una ricetta
{
    cercaWidget c(m, nullptr);
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

    emit ChangeR();









}

void mainwindow::update()
{
    //MI serve x cancellare se c'è qualcosa
    if(centralGroupBox->count() != 0){
        auto item = centralGroupBox->takeAt(0);
        delete item->widget();
        delete item;
    }

    //riempio la schermata
    auto it= m->getRicette();

    for(auto *r :it)

    {
        widget *ric= new widget(r);
        centralGroupBox->addWidget(ric);



    }
    widget *ric=new widget(*it.end());
    centralGroupBox->addWidget(ric);
    centralGroupBox->addStretch(1);
    show();
}







