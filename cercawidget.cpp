#include "cercawidget.h"
#include "cercawidgetresult.h"

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

cercaWidget::cercaWidget(ricette* p, QWidget *parent):

    QDialog(parent),
    r(p),
    m(new Model),
    name(new QLineEdit),
    result(new QVBoxLayout)

{
    QVBoxLayout *main_l=new QVBoxLayout;
    QVBoxLayout *name_l=new QVBoxLayout;



    QVBoxLayout *button = new QVBoxLayout;


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


ricette *cercaWidget::getR()
{
    return r;
}

void cercaWidget::cerca()
{
    cercaWidgetResult c;
    c.filtra(getNome());
    //c.exec();

    //show();

}
