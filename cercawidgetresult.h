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

    Model *m;
    QVBoxLayout *result;

public:
    explicit cercaWidgetResult(Model*, QWidget * parent = nullptr);
    void filtra(QString, string);




};

#endif // CERCAWIDGETRESULT_H
