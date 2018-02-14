#include "barvie.h"

BarVie::BarVie(unsigned int vieMax, QGraphicsItem *parent) : GraphicsProgressBar(parent)
{
    this->setMaximun(vieMax);
    this->setValue(vieMax);
    this->choixCouleur();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::recevoirDegat(int degat){
    int vie=this->getValue();
    vie-=degat;
    if(vie<0){
        vie=0;
    }
    this->setValue(vie);
    this->choixCouleur();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::recevoirSoin(int soin){

    this->setValue(this->getValue()+soin);
    this->choixCouleur();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::choixCouleur(){
    qreal p=this->calculFinBar();
    QColor c;
    if(p<=0.25){
       c=QColor(255,50,50);
    }
    else{if(p<=0.50){
            c=QColor(255,255,50);
        }
        else{
           c=QColor(55,255,50);
        }

    }
    this->setColor(c);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::setValue(unsigned int val){
    this->GraphicsProgressBar::setValue(val);
    this->choixCouleur();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::setMaximun(unsigned int max){
    this->GraphicsProgressBar::setMaximun(max);
    this->choixCouleur();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
