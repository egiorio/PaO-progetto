#ifndef CERCAWIDGETRESULT_H
#define CERCAWIDGETRESULT_H
#include "add.h"
#include"model.h"


#include <QDialog>
#include <QVBoxLayout>


class cercaWidgetResult: public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *result;
    Model *m;

public:
    explicit cercaWidgetResult(QWidget * parent = nullptr);
    bool filtra(QString);

public slots:
    int eccez();


};

#endif // CERCAWIDGETRESULT_H