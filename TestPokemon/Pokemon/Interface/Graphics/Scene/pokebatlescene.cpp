#include "pokebatlescene.h"

PokeBatleScene::PokeBatleScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(88,88,88)));
    this->setSceneRect(0,0,300,300);
}

PokeBatleScene::~PokeBatleScene() throw(){

}
