#include "graphicstextarea.h"
#include <QPainter>

//-------------------------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------------------------
//-------------------------------------------------------------------------------------------
GraphicsTextArea::GraphicsTextArea(qreal largeur, qreal hauteur ,QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->setGeometry(0,0,largeur,hauteur);
    this->text = new QGraphicsTextItem("Un combat debute",this);
    this->nextText = new QList<QString*>();
}
//-------------------------------------------------------------------------------------------
//---------------------------Destructeur-----------------------------------------------------
//-------------------------------------------------------------------------------------------
GraphicsTextArea::~GraphicsTextArea() throw(){
    for(int i = 0 ; i < this->nextText->size() ; i++){
        delete this->nextText->at(i);
    }
    delete nextText;
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
    this->nextText->append(new QString(text));
    if(this->nextText->size() == 1){
        this->afficheNextText();

    }
}
//-------------------------------------------------------------------------------------------
void GraphicsTextArea::afficheNextText(){
    QString& text = *(this->nextText->first());
    this->text->setPlainText(text);
    if(this->text->boundingRect().width() > this->boundingRect().width()){
        this->text->setPlainText(text.insert(text.size()/(this->text->boundingRect().width()/this->boundingRect().width()),'\n'));
    }
}
//-------------------------------------------------------------------------------------------
void GraphicsTextArea::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(this->nextText->size() > 0){
        this->nextText->removeFirst();
        if(this->nextText->size() == 0){
            emit endText();
        }
        else{
            this->afficheNextText();
        }
    }
}
