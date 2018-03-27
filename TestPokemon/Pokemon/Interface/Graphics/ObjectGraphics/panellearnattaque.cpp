#include "panellearnattaque.h"
#include <QPainter>
#include "./learnattaquebutton.h"
#include <QGraphicsLinearLayout>

PanelLearnAttaque::PanelLearnAttaque(PokemonInterface& you,QString nomAttaque,QGraphicsWidget *parent) : QGraphicsWidget(parent)
{
    QGraphicsLinearLayout* layout = new QGraphicsLinearLayout(Qt::Vertical,this);

    for(uint i = 0 ; i <= you.getNbAttaque() ; i++){
        LearnAttaqueButton* b = new LearnAttaqueButton(you,i,nomAttaque,this);
        QObject::connect(b,SIGNAL(cliked()),SLOT(end_slot()));
        layout->addItem(b);

    }
    layout->activate();
}

PanelLearnAttaque::~PanelLearnAttaque() throw (){

}


void PanelLearnAttaque::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRect(r);
}

void PanelLearnAttaque::end_slot(){
    this->hide();
}
