#include "mainwindowspoke.h"
#include "Scene/pokebatlescene.h"
#include <iostream>

#include "../../Pokemon/Pokemon/pokemonfactory.h"

//----------------------------------------------------------------------
//-----------------------------constructeur-----------------------------
//----------------------------------------------------------------------

MainWindowsPoke::MainWindowsPoke(PokemonInterface* y,QWidget *parent) : QMainWindow(parent)
{
    this->view = new GraphicsView(this);
    this->other = NULL;
    this->you = y;

    this->createBattleScene();
    this->setCentralWidget(view);
}

//----------------------------------------------------------------------
//------------------------------Destructeur-----------------------------
//----------------------------------------------------------------------

MainWindowsPoke::~MainWindowsPoke() throw(){
    if(other!=NULL){
        delete other;
    }
}

//----------------------------------------------------------------------
//------------------------------fonction--------------------------------
//----------------------------------------------------------------------
void MainWindowsPoke::createBattleScene(){
    you->soinComplet();
    unsigned int lv = (rand()%(you->getLevel()+1))+1;

    if(other != NULL){
        delete other;
    }

    other = PokemonFactory::getInstance().createRandomPokemon(lv);
    if(other == NULL){
        std::cerr << "Probleme Allocation ennemie " << std::endl;
    }
    PokeBatleScene* s = new PokeBatleScene(you,other,view);
    this->view->setScene(s);
    QObject::connect(s,SIGNAL(endBattle()),SLOT(createBattleScene()));
    QObject::connect(s,SIGNAL(endBattleEvolution()),SLOT(createEvolutionScene()));
}
//----------------------------------------------------------------------
void MainWindowsPoke::createEvolutionScene(){

}

