

#ifndef ADD_H
#define ADD_H
#include <QButtonGroup>
#include <QComboBox>
#include<QDialog>
#include<QLineEdit>
#include<QLabel>
#include<QRadioButton>
#include "ricette.h"

class add :public QDialog
{
    Q_OBJECT
private:
    ricette* ric;
    QComboBox *tipo_ricetta;
    QLineEdit *name;
    QLineEdit *prezzo;
    QRadioButton *cottura;

    QLineEdit *tipo;
    QLabel *label;



private slots:
    void setFields(const QString &);
    ricette* addRicetta(const QString&);
//public slots:
    //ricette* addRicetta(const string&);



public:
    explicit add(ricette* = nullptr, QWidget * = nullptr);
    QSize  sizeHint() const;
    string getType() const;
    string getNome() const;
    double getPrezzo() const;
    bool getCottura() const;
    string getTipo() const;

    ricette* getR() const;


};

#endif // ADD_H
