#include "graphicstextarea.h"
#include <QPainter>

//-------------------------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------------------------
//-------------------------------------------------------------------------------------------
GraphicsTextArea::GraphicsTextArea(qreal largeur, qreal hauteur ,QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->setGeometry(0,0,largeur,hauteur);
    this->text = new QGraphicsTextItem("Un combat debute",this);
}
//-------------------------------------------------------------------------------------------
//---------------------------Destructeur-----------------------------------------------------
//-------------------------------------------------------------------------------------------
GraphicsTextArea::~GraphicsTextArea() throw(){

}
//-------------------------------------------------------------------------------------------
//---------------------------Fonction--------------------------------------------------------
//-------------------------------------------------------------------------------------------
void GraphicsTextArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRect(r);
}
//-------------------------------------------------------------------------------------------
void GraphicsTextArea::setText(const QString text){
    this->text->setPlainText(text);
    if(this->text->boundingRect().width() > this->boundingRect().width()){
        QString t = text;
        this->text->setPlainText(t.insert(t.size()/(this->text->boundingRect().width()/this->boundingRect().width()),'\n'));
    }
}
