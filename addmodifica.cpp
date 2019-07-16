#include "addmodifica.h"
#include<add.h>

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>


addModifica::addModifica(double p, QWidget *parent):
    QDialog (parent),


    _prezzo(new QLineEdit(QString::number(p))),
    _cottura(new QRadioButton())

{
    QVBoxLayout *main_l = new QVBoxLayout();
    QHBoxLayout *prezzo_l= new QHBoxLayout();
    QHBoxLayout *cottura_l= new QHBoxLayout();

    prezzo_l->addWidget(new QLabel("Inserire il nuovo prezzo: "));
    prezzo_l->addWidget(_prezzo);
    prezzo_l->addStretch(1);

    main_l->addLayout(prezzo_l);

    cottura_l->addWidget(new QLabel("Spuntare se NON necessaria cottura"));
    _cottura->setText(tr("Non necessaria cottura"));
    _cottura->setChecked(0);
    cottura_l->addWidget(_cottura);

    main_l->addLayout(cottura_l);

    QHBoxLayout *buttons=new QHBoxLayout();

    QPushButton *ok=new QPushButton("ok");
    QPushButton *cancel=new QPushButton("Cancella");
    buttons->addStretch(1);
    buttons->addWidget(ok);
    buttons->addWidget(cancel);

    main_l->addLayout(buttons);
    setLayout(main_l);
    show();

    connect(ok, &QPushButton::clicked, this, &add::accept );

    connect(cancel, &QPushButton::clicked, this, &add::reject);


}

double addModifica::getP() const
{
    return _prezzo->text().toDouble();

}

bool addModifica::getC() const
{
    return _cottura->isChecked();
}


