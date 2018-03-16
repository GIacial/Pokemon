#include "barvie.h"

BarVie::BarVie(unsigned int vieMax, QGraphicsItem *parent) : GraphicsProgressBar(parent)
{
    this->setMaximun(vieMax);
    this->setValue(vieMax);
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
void BarVie::setValue(int val){
    this->GraphicsProgressBar::setValue(val);
    this->choixCouleur();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BarVie::setMaximun( int max){
    this->GraphicsProgressBar::setMaximun(max);
    this->choixCouleur();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
