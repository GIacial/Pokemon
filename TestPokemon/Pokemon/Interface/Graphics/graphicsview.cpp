#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsView::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    QGraphicsView::fitInView(QGraphicsView::sceneRect(), Qt::KeepAspectRatio);//permet de garder le ratio de taille a la remodif de la taille
}

