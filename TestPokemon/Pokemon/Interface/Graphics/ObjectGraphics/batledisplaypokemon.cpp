#include "batledisplaypokemon.h"
#include <QPainter>

//------------------------------------------------------------------------------------------------
//------------------------------Constructeur------------------------------------------------------
//------------------------------------------------------------------------------------------------
BatleDisplayPokemon::BatleDisplayPokemon(PokemonInterface* poke,QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->poke = poke;
    this->displayLife = new BarVie(poke->getMaxPv(),this);
    this->nom = new QGraphicsTextItem(poke->getNom(),this);
    this->lv = new QGraphicsTextItem("Lv : "+QString::number(poke->getLevel()),this);

    this->nom->setPos(MARGE,MARGE/2);

    QRectF nomRect = nom->boundingRect();
    this->lv->setPos(nomRect.width()+10+MARGE,MARGE/2 );
    this->displayLife->setGeometry(MARGE/2,nomRect.height()+MARGE/2,nomRect.width()*2,this->displayLife->boundingRect().height());
    this->setGeometry(0,0,displayLife->boundingRect().width()+MARGE,nomRect.height()+displayLife->boundingRect().height()+MARGE);

    QObject::connect(poke,SIGNAL(changedPv(int)),displayLife,SLOT(setValue(int)));
    QObject::connect(poke,SIGNAL(changedPvMax(int)),displayLife,SLOT(setMaximun(int)));
    QObject::connect(poke,SIGNAL(changedLevel(uint)),this,SLOT(changedLevel(uint)));
}
//------------------------------------------------------------------------------------------------
//-------------------------------Destructeur------------------------------------------------------
//------------------------------------------------------------------------------------------------
BatleDisplayPokemon::~BatleDisplayPokemon() throw (){

}
//------------------------------------------------------------------------------------------------
//-------------------------------fonction---------------------------------------------------------
//------------------------------------------------------------------------------------------------
void BatleDisplayPokemon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,QColor(255,255,255,255));
    grad.setColorAt(1,QColor(180,180,180,255));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRoundRect(r);
}
//------------------------------------------------------------------------------------------------
//-------------------------------slot-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void BatleDisplayPokemon::changedLevel(const unsigned int level){
    this->lv->setPlainText("Lv : "+QString::number(level));
}
