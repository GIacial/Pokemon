#include "learnattaquebutton.h"

#include <QGraphicsTextItem>
#include <QPainter>

LearnAttaqueButton::LearnAttaqueButton(PokemonInterface &you, uint i, QString nomAttak, QGraphicsWidget *parent) : QGraphicsWidget(parent),you(you)
{
    this->i = new uint(i);
    QGraphicsTextItem* nomAttaque = new QGraphicsTextItem(this);
    if(i < you.getNbAttaque()){
        nomAttaque->setPlainText(you.getNomAttaque(i));
    }
    else{
        //recup le nom de l'attaque a apprendre
        nomAttaque->setPlainText(nomAttak);
    }
    this->setMinimumWidth(nomAttaque->boundingRect().width());
    this->setMaximumHeight(nomAttaque->boundingRect().height());
    this->setGeometry(0,0,nomAttaque->boundingRect().width(),nomAttaque->boundingRect().height());
}

LearnAttaqueButton::~LearnAttaqueButton() throw (){
    delete i;
}


void LearnAttaqueButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRoundRect(r);
}

void LearnAttaqueButton::mousePressEvent(QGraphicsSceneMouseEvent *){
    you.apprendreAttaque(*i);
    emit cliked();
}
