#ifndef WIDGET_H
#define WIDGET_H

#include "model.h"
#include "ricette.h"
#include <QFrame>
#include<QWidget>

class widget: public QFrame
{
    Q_OBJECT
private:
    //Model::Index ric;
    ricette* p;
    Model *m;


public:
    explicit widget(/*const Model::Index&,*/ ricette*,   QWidget * = nullptr);
    ricette* getRicetta() const;

signals:
    void remove(widget*);
    void change();
private slots:
    void set();
public slots:
    void modR();
};

#endif // WIDGET_H
