#include "pokebatlescene.h"



PokeBatleScene::PokeBatleScene(PokemonInterface *y, PokemonInterface *o, QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(88,88,88)));
    this->setSceneRect(0,0,300,300);
    this->kernel = new PokeBatleSceneKernel(*this,y,o);


    this->youDisplay = new BatleDisplayPokemon(y);
    this->otherDisplay = new BatleDisplayPokemon(o);
    this->textDisplay = new GraphicsTextArea(this->sceneRect().width(),this->sceneRect().height()*HAUTEUR_TEXT_POURCENTAGE);
    this->attaque = new AttaquePanel(*kernel);

    this->addItem(this->youDisplay);
    this->addItem(this->otherDisplay);
    this->addItem(textDisplay);
    this->addItem(attaque);

    this->textDisplay->setPos(0,this->sceneRect().height()-this->textDisplay->boundingRect().height());
    this->youDisplay->setPos(this->sceneRect().width()-this->youDisplay->boundingRect().width(),this->sceneRect().height()-this->youDisplay->boundingRect().height()-this->textDisplay->boundingRect().height()-1);
    this->attaque->setPos(50,50);


    this->kernel->launchCombat();
}

PokeBatleScene::~PokeBatleScene() throw(){
    delete youDisplay;
    delete otherDisplay;
    delete textDisplay;
    delete attaque;
    delete kernel;
}

void PokeBatleScene::afficheTexte(QString m){
    this->textDisplay->setText(m);
}

void PokeBatleScene::apprendreAttaque(unsigned int *t){

}

void PokeBatleScene::evoluer(bool *t){

}
