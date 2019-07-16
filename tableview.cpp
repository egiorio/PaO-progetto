#include "tableview.h"
#include<QMouseEvent>

TableView::TableView(QWidget* parent): QTableView (parent)
{ //rendere possibile la selezione di un singolo elemento alla volta
    setSelectionBehavior((QAbstractItemView::SelectRows));


}

/*QSize TableView::sizeHint() const{
    return QSize(1200, 400);
}

void TableView::mousePressEvent(QMouseEvent* event){
    if(!indexAt((event->pos()).isValid()){
            clearSelection();
            selectionModel()->clearCurrentIndex();
}
            QTableView::mousePressEvent(event);

}*/

