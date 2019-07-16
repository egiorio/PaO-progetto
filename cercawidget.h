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
    ricette* r;
    Model *m;
    QLineEdit *name;
    QVBoxLayout *result;

public:
    explicit cercaWidget(ricette* = nullptr,   QWidget* = nullptr);
    QString getNome() const;
    ricette* getR();
public slots:
    void cerca();


};

#endif // CERCAWIDGET_H
