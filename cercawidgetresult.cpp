#include "cercawidgetresult.h"
#include "cercawidget.h"
#include "widget.h"

#include <QScrollArea>

cercaWidgetResult::cercaWidgetResult( QWidget* parent):
    QDialog (parent),
    m(new Model),
    result(new QVBoxLayout)
{
    //setMaximumWidth(300);
    //setMaximumWidth(500);
    setWindowTitle("Risultati della ricerca");



    QVBoxLayout *main_l= new QVBoxLayout;
    QScrollArea *scroll= new QScrollArea;
    QWidget *widget= new QWidget;
    widget->setLayout(result);
    scroll->setWidget(widget);
    widget->setFixedWidth(480);
    scroll->setWidgetResizable(false);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    main_l->addWidget(scroll);
    setLayout(main_l);
    show();
}

bool cercaWidgetResult::filtra(QString name)
{
    cercaWidgetResult cer;
    //if(cer.exec()){
        auto resul =m->cercaR(name);
        for(auto &x: resul){
            //widget w=new widget(&x);

            //result->addWidget(w);
        }
        show();
        return true;
   // }
    //else {
      //  return false;
    //}

}

int cercaWidgetResult::eccez()
{
    //return  filtra() ? QDialog::exec() : 0;
}
