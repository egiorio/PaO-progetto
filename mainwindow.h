#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "model.h"
#include "widget.h"


#include<QMainWindow>
#include<QWidget>
#include<QFile>
#include <QGroupBox>
#include <QVBoxLayout>



class Model; // definizioni incomplete
class TableView;
class QCloseEvent;
class QComboBox;
class QLineEdit;

class mainwindow : public QMainWindow
{
        Q_OBJECT
private:
//puntatore a model
    Model* m;
    QVBoxLayout *centralGroupBox;




public:
    mainwindow(QWidget *p =nullptr);
    ~mainwindow() override = default;
    QSize sizeHint() const override;

public slots:
   void addOrder();
   void removeR(widget*);
   void cercaR();
   void save();
   void load();




};

#endif // MAINWINDOW_H

