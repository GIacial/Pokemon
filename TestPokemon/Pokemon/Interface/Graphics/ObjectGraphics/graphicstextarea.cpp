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
    QString& texte = *(this->nextText->first());
    this->text->setPlainText(texte);
    if(this->text->boundingRect().width() > this->boundingRect().width()){
        this->addReturnLigne(texte);
        this->text->setPlainText(texte);
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
//-------------------------------------------------------------------------------------------
void GraphicsTextArea::addReturnLigne(QString& texte){
    double nbLigne = (this->text->boundingRect().width()/(this->boundingRect().width()-15));
    int nb = 1;
    while(nb < nbLigne){
        int place = nb*texte.size()/nbLigne;
        if(place < texte.size() && texte.contains(' ')){
            while(place >= 0 && texte.at(place) != ' '){
                place --;
            }

        }
        texte.insert(place+1,'\n');
        nb++;
    }

}
