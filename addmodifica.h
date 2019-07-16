#ifndef ADDMODIFICA_H
#define ADDMODIFICA_H
#include "ricette.h"
#include "add.h"

#include<QDialog>
#include<QLineEdit>
#include<QString>
#include <QRadioButton>

class addModifica: public QDialog
{
    Q_OBJECT
private:

    QLineEdit *_prezzo;
    QRadioButton *_cottura;

public:
    explicit addModifica(double, QWidget * = nullptr );


    double getP() const;
    bool getC() const;


};

#endif // ADDMODIFICA_H
