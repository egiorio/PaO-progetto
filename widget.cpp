#include "widget.h"
#include "add.h"
#include "ricette.h"
#include "primo.h"
#include "secondo.h"
#include "dolce.h"
#include "addmodifica.h"

#include<QPushButton>
#include<QHBoxLayout>
#include <QLabel>
#include <QTextEdit>

widget::widget( ricette* pi,  QWidget *parent):
    QFrame (parent), p(pi)
{
    QHBoxLayout *main_l = new QHBoxLayout;
    QVBoxLayout *special=new QVBoxLayout;

    //setFrameStyle(QFrame::Panel | QFrame::Raised);

    QHBoxLayout *name_l=new QHBoxLayout;
    name_l->setSizeConstraint(QLayout::SetMinAndMaxSize);

    QHBoxLayout *prez_l=new QHBoxLayout;
    QHBoxLayout *cot_l=new QHBoxLayout;


    QLabel *name= new QLabel("Nome: "    + QString::fromStdString(p->getNome()) );
    QLabel *prez= new QLabel("Prezzo: " + QString::number(p->getPrezzo()));
    QLabel *cott=new QLabel;
    cott->setText(QString("Cottura :") + (p->getCottura() ? "1" : "0"));
    name_l->addWidget(name);
    name_l->addStretch(1);
    prez_l->addWidget(prez);
    prez_l->addStretch(1);
    cot_l->addWidget(cott);
    cot_l->addStretch(1);
    special->addLayout(name_l);
    special->addLayout(prez_l);
    special->addLayout(cot_l);
    main_l->addLayout(special);

    QHBoxLayout *tip_l=new QHBoxLayout;
    QHBoxLayout *clas_l=new QHBoxLayout;
    QHBoxLayout *cat_l=new QHBoxLayout;





    if(dynamic_cast<primo*>(p)){
        primo* pr=dynamic_cast<primo*>(p);
        QLabel *tipo= new QLabel("Tipo alimentare: " + QString::fromStdString(pr->getTipo()));

        tip_l->addWidget(tipo);
        tip_l->addStretch(1);
        special->addLayout(tip_l);

        main_l->addLayout(special);
    }
    else{
        if(dynamic_cast<secondo*>(p)){
            secondo* sec=dynamic_cast<secondo*>(p);
            QLabel *classe= new QLabel("Classe alimentare: " + QString::fromStdString(sec->getClasse()));
            clas_l->addWidget(classe);
            clas_l->addStretch(1);
            special->addLayout(clas_l);

            main_l->addLayout(special);
         }
        else {
            if(dynamic_cast<dolce*>(p)){
               dolce* d=dynamic_cast<dolce*>(p);
            QLabel *categoria=new QLabel("Categoria alimentare" +  QString::fromStdString(d->getCategoria()));
            cat_l->addWidget(categoria);
            cat_l->addStretch(1);
            special->addLayout(cat_l);

            main_l->addLayout(special);
        }
        }
}





    QPushButton* del=new QPushButton("Rimuovi ricetta");
    special->addWidget(del);
    main_l->addLayout(special);
    //connect(del, &QPushButton::clicked, this, &Model::remove());
    connect(del, &QPushButton::clicked, this, [this](){
        emit remove(this);
                });


    QPushButton *mod=new QPushButton("Modifica ricetta");
    connect(mod, &QPushButton::clicked, this, &widget::modR);



    connect(this, &widget::change, cott, [this, cott]()
    {
        cott->setText(QString("Cottura :") + ((this->p)->getCottura() ? "1" : "0"));
    });

    connect(this, &widget::change, prez, [this, prez](){
            prez->setText(("Prezzo: ") + QString::number((this->p)->getPrezzo()));
});


    special->addWidget(mod);
    main_l->addLayout(special);


    setLayout(main_l);

}

ricette* widget::getRicetta() const
{
    return p;


}

void widget::set()
{


}

void widget::modR()
{

    addModifica edit_dialog(p->getPrezzo());
    //if(edit_dialog.exec()){
    edit_dialog.exec();
       p->setPrezzo(edit_dialog.getP());
       p->setCottura(edit_dialog.getC());

    //}

    emit change();
}
