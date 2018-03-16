#include "attaquebutton.h"

#include <QPainter>

AttaqueButton::AttaqueButton(AbstractCombatInterface& kernel,unsigned int i,QGraphicsItem *parent) : QGraphicsWidget(parent), kernel(kernel)
{
    this->text = new QGraphicsTextItem(this);
    this->attaqueNumber = new uint(i);
    if(i < kernel.getSystemCombat().getNbAttaque()){
        this->text->setPlainText(kernel.getSystemCombat().getNomAttaqueCreature(CibleKM_COMBAT::ME,i));
    }
    else{
        this->hide();
    }
}

AttaqueButton::~AttaqueButton() throw (){
    delete attaqueNumber;
}

void AttaqueButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRoundRect(r);
}

void AttaqueButton::mousePressEvent(QGraphicsSceneMouseEvent *){
    this->kernel.useAttaque(*attaqueNumber);
}
