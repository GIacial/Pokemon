#include "attaquepanel.h"

#include <QGraphicsGridLayout>
#include <QPainter>

AttaquePanel::AttaquePanel(AbstractCombatInterface &kernel, QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->buttons = new QList<AttaqueButton*>();
    QGraphicsGridLayout* grid = new QGraphicsGridLayout(this);
    uint nbAttaque = kernel.getSystemCombat().getNbAttaque();
    uint ligneNb = sqrt(nbAttaque);
    for(unsigned int i = 0 ; i <nbAttaque  ; i++){
        AttaqueButton* b = new AttaqueButton(kernel,i,this);
        this->buttons->append(b);
        grid->addItem(b,i%ligneNb,i/ligneNb);
    }
    grid->activate();
}

AttaquePanel::~AttaquePanel() throw (){
    delete buttons;
}

void AttaquePanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRect(r);
}
