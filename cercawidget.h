#ifndef CERCAWIDGET_H
#define CERCAWIDGET_H

#include <QComboBox>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>

#include "ricette.h"
#include "model.h"



class cercaWidget: public QDialog
{
    Q_OBJECT
private:

    Model *m;
    QLineEdit *name;
    QVBoxLayout *result;
    QComboBox *tipo_ricetta;

public:
     cercaWidget(Model* model,  QWidget* = nullptr);
    QString getNome() const;

    string getType() const;
public slots:
    void cerca();


};

#endif // CERCAWIDGET_H
