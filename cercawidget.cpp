#include "cercawidget.h"
#include "cercawidgetresult.h"
#include "widget.h"

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

cercaWidget::cercaWidget(Model* model,QWidget *parent):

    QDialog(parent),
    m(model),
    name(new QLineEdit),
    result(new QVBoxLayout),
    tipo_ricetta(new QComboBox(this))

{
    QVBoxLayout *main_l=new QVBoxLayout;
    QVBoxLayout *name_l=new QVBoxLayout;
    QVBoxLayout *tipo_l=new QVBoxLayout;



    QVBoxLayout *button = new QVBoxLayout;

    tipo_ricetta->addItem(tr("Primo"));
    tipo_ricetta->addItem(tr("Secondo"));
    tipo_ricetta->addItem(tr("Dolce"));
    tipo_l->addWidget(tipo_ricetta);
    tipo_l->addStretch(1);

    main_l->addLayout(tipo_l);


    name_l->addWidget(new QLabel("Nome ricetta: "));
    name_l->addWidget(name);
    name_l->addStretch(1);
    main_l->addLayout(name_l);

    QPushButton *cerca= new QPushButton("Cerca");
    QPushButton *cancel=new QPushButton("Cancella");
    button->addStretch(1);
    button->addWidget(cerca);
    button->addWidget(cancel);
    main_l->addLayout(button);

    setLayout(main_l);
    show();

    connect(cerca, &QPushButton::clicked, this, &cercaWidget::cerca);


    connect(cancel, &QPushButton::clicked, this, &cercaWidget::reject );
}

QString cercaWidget::getNome() const
{
    return name->text();
}




std::string cercaWidget::getType() const
{
    return tipo_ricetta->currentText().toStdString();
}

void cercaWidget::cerca()
{
    cercaWidgetResult c(m);
    c.filtra(getNome(), getType());


}
