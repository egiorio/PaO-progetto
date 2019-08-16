#include "cercawidgetresult.h"
#include "cercawidget.h"
#include "widget.h"

#include <QScrollArea>

cercaWidgetResult::cercaWidgetResult(Model* model, QWidget* parent):
    QDialog (parent),
    m(model),
    result(new QVBoxLayout)
{
    //setMaximumWidth(300);
    //setMaximumWidth(500);
    setWindowTitle("Risultati della ricerca");



    QVBoxLayout *main_l= new QVBoxLayout;
    QScrollArea *scroll= new QScrollArea;
    QWidget *widget_L= new QWidget;
    widget_L->setLayout(result);
    scroll->setWidget(widget_L);
    widget_L->setFixedWidth(500);


    scroll->setWidgetResizable(false);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    main_l->addWidget(scroll);


main_l->addLayout(result);

    setLayout(main_l);
    show();
}

void cercaWidgetResult::filtra(QString name, string tipo)
{
    cercaWidgetResult cer(m);


        cer.exec();
        std::vector<ricette*> resul = m->cercaR(name, tipo);
        auto x=resul.begin();
        while(x != resul.end()){
            widget *w=new widget(*x);
            result->addWidget(w);
            ++x;
            if(x == resul.end()){
                widget*ric=new widget(*resul.end());
                result->addWidget(ric);
            }


        }



    show();

   //}
    //else {



        //return false;
    //}

}

