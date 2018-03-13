#include "pokebatlescene.h"

#include "../ObjectGraphics/batledisplaypokemon.h"

#include "../../../Pokemon/Pokemon/fakemon.h"

PokeBatleScene::PokeBatleScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(88,88,88)));
    this->setSceneRect(0,0,300,300);

    PokemonInterface* a = new Fakemon(5);
    a->setParent(this);
    this->addItem(new BatleDisplayPokemon(a));
}

PokeBatleScene::~PokeBatleScene() throw(){

}
