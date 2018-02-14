#include "graphicsprogressbar.h"
#include <QPainter>
#include <QTimer>

GraphicsProgressBar::GraphicsProgressBar(QGraphicsItem *parent) : QGraphicsWidget(parent)
{
    this->montantActuel=0;
    this->montantMax=100;
    this->montantAnimation=0;
    this->couleurBar= QColor(0,255,0);
    this->setGeometry(0,0,46,10);

    this->timerAnimationBar= new QTimer(this);
    this->timerAnimationBar->setSingleShot(true);
    QObject::connect(this->timerAnimationBar,SIGNAL(timeout()),this,SLOT(refresh()) );

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsProgressBar::~GraphicsProgressBar(){
    if(!this->timerAnimationBar.isNull()){
        delete this->timerAnimationBar;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF r=this->boundingRect();

  //bar coloré
    QLinearGradient grad=  QLinearGradient(r.topLeft(),r.topRight());
    grad.setColorAt(0,couleurBar);
    if(this->montantAnimation>0.001){
        grad.setColorAt(this->montantAnimation-0.001,this->couleurBar);
    }
    grad.setColorAt(this->montantAnimation,QColor(0,0,0,0));

    painter->setBrush(grad);
    painter->setPen(Qt::black);
    painter->drawRoundRect(r);

    this->animationBar();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::setMaximun(unsigned int max){
    this->montantMax=max;
    this->verifValInfMax();
    this->update();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::setValue(unsigned int val){
    this->montantActuel=val;
    this->verifValInfMax();
    this->update();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::setColor(QColor color){
    this->couleurBar=color;
    update();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int GraphicsProgressBar::getMaximun()const{
    return this->montantMax;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int GraphicsProgressBar::getValue()const{
    return this->montantActuel;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QColor GraphicsProgressBar::getColor()const{
    return this->couleurBar;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::verifValInfMax(){
    if(this->montantActuel>this->montantMax){
        this->montantActuel=this->montantMax;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::animationBar(){
    qreal diff = this->calculFinBar() -this->montantAnimation;
    if(diff <-GraphicsProgressBar::pasAnimationBar || diff>GraphicsProgressBar::pasAnimationBar){
        if(diff<0){
            this->montantAnimation-=GraphicsProgressBar::pasAnimationBar;
        }
        else{
            this->montantAnimation+=GraphicsProgressBar::pasAnimationBar;
        }
        this->timerAnimationBar->start(GraphicsProgressBar::tempsAnimationBar);
    }


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
qreal GraphicsProgressBar::calculFinBar() const{
    return (qreal)this->montantActuel/this->montantMax;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void GraphicsProgressBar::refresh(){
    this->update();
}
