#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include<QTableView>

class TableView : public QTableView
{

public:
    TableView(QWidget* = nullptr);
    //QSize sizeHint() const override;
    //void mousePressEvent(QMouseEvent*) override;
};

#endif // TABLEVIEW_H
