#include "graphicsgif.h"
#include <QPainter>
#include <iostream>

GraphicsGif::GraphicsGif(QString adr, QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->gif = new QMovie(adr);
    this->img = new QGraphicsPixmapItem(gif->currentPixmap(),this);
    QObject::connect(gif,SIGNAL(updated(QRect)),this,SLOT(changedFrame(QRect)));
    QObject::connect(gif,SIGNAL(finished()),gif,SLOT(start()));

    gif->start();
}

GraphicsGif::~GraphicsGif() throw (){
    delete gif;
}

void GraphicsGif::changedFrame(QRect){
    this->img->setPixmap(gif->currentPixmap());
}

QRectF GraphicsGif::boundingRect()const{
    QPixmap a = this->gif->currentPixmap();
    return QRectF(0,0, a.width(),a.height());
}

void GraphicsGif::mousePressEvent(QGraphicsSceneMouseEvent *){
    emit clicked();
}

