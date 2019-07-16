#include "add.h"
#include "primo.h"
#include "secondo.h"
#include "dolce.h"
#include "ricette.h"


#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>



void add::setFields(const QString & r)
{

    tipo->setVisible(true);

    if(r=="Primo"){
        label->setText("Indicare se Vegetariana o Onnivora: ");
        tipo->setVisible(true);
    }
    else{
        if(r=="Secondo"){
            label->setText("Indicare se Carne o Pesce: ");
            tipo->setVisible(true);
        }
        else {
            if(r=="Dolce"){
                   label->setText("Indicare se Vegana o non vegana: ");
                   tipo->setVisible(true);
            }
        }
    }


}

ricette *add::addRicetta(const QString& a)
{  /* QString na=getNome();
    string n=na.toStdString();
    double pr=getPrezzo();
    bool c=getCottura();
    if(a=="Primo"){
        QString t=getTipo();
        string np=t.toStdString();
        primo* p=new primo(n, pr, c, np);
        ric=dynamic_cast<ricette*>(p);
        return p;
    }
    else {
        if(a=="Secondo"){
            string t=getClasse();
            secondo* p=new secondo(n, pr,c, t);
            ric=dynamic_cast<ricette*>(p);
            return p;
        }
        else{
            string t=getCategoria();
            dolce* p=new dolce(n, pr, c, t);
            ric=dynamic_cast<ricette*>(p);
            return p;
        }
    }
*/
}

add::add( ricette* r, QWidget *parent):

    QDialog (parent),
    ric(r),
    tipo_ricetta(new QComboBox(this)),
    name(new QLineEdit),
    prezzo(new QLineEdit),
    cottura( new QRadioButton),
    tipo(new QLineEdit),
    label(new QLabel("Indicare se Vegetariana o Onnivora: "))
    /*_classe(new QLineEdit),
    categoria(new QLineEdit)*/

{
QVBoxLayout *main_l = new QVBoxLayout;
QVBoxLayout *name_l = new QVBoxLayout;
QVBoxLayout *prezzo_l = new QVBoxLayout;
QVBoxLayout *cottura_box = new QVBoxLayout;


QVBoxLayout *menu_box= new QVBoxLayout;
QVBoxLayout *buttons = new QVBoxLayout;



//menù di tipi

tipo_ricetta->addItem(tr("Primo"));
tipo_ricetta->addItem(tr("Secondo"));
tipo_ricetta->addItem(tr("Dolce"));
main_l->addWidget(tipo_ricetta);

connect(tipo_ricetta, SIGNAL(currentTextChanged(const QString&)), this, SLOT(setFields(const QString &)));
connect(tipo_ricetta, SIGNAL(currentTextChanged(const QString&)), this, SLOT(addRicetta(const QString &)));




//set name
name->setMaximumWidth(200);
name_l->addWidget(new QLabel("Nome Ricetta: "));
name_l->addWidget(name);
//name_l->addStretch(1);

main_l ->addLayout(name_l);

//set prezzo
prezzo->setMaximumWidth(200);
prezzo_l->addWidget(new QLabel("Prezzo ricetta: "));
prezzo_l->addWidget(prezzo);
//prezzo_l->addStretch(1);

main_l->addLayout(prezzo_l);

//set cottura
cottura_box->addWidget(new QLabel("Spuntare se non necessaria cottura : "));
cottura->setText(tr("NON necessita di cottura"));
cottura->setChecked(0);
cottura_box->addWidget(cottura);
cottura_box->addStretch(1);


main_l->addLayout(cottura_box);

//Set tipo


QVBoxLayout *tipo_l= new QVBoxLayout;
tipo_l->addWidget(label);

tipo_l->addWidget(tipo);
main_l->addLayout(tipo_l);

main_l->addLayout(menu_box);



//pulsanti

QPushButton *ok_button= new QPushButton("Aggiungi");
QPushButton *cancel= new QPushButton("Cancella");
//buttons->addStretch(1);
buttons->addWidget(ok_button);
buttons->addWidget(cancel);
main_l->addLayout(buttons);

connect(ok_button, &QPushButton::clicked, this, &add::accept);
connect(cancel, &QPushButton::clicked, this, &add::reject );


setLayout(main_l);


}

QSize add::sizeHint() const{
    return QSize(300, 400);

}

string add::getType() const
{
    return tipo_ricetta->currentText().toStdString();


}
string add::getNome() const
{

    return name->text().toStdString();
}

double add::getPrezzo() const
{
    return prezzo->text().toDouble();

}

bool add::getCottura() const
{

    return cottura->isChecked();
}
string add::getTipo() const
{

    return tipo->text().toStdString();
}


ricette *add::getR() const
{

    return ric;
}


