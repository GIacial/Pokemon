#include "mainwindowspoke.h"
#include "Scene/pokebatlescene.h"
#include <iostream>

#include "../../Pokemon/Pokemon/pokemonfactory.h"

#include "Scene/evolutionscene.h"
#include "Scene/learnattaquescene.h"

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
    delete this->view->scene();                             //supprime la vielle scene
    this->view->setScene(s);
    QObject::connect(s,SIGNAL(endBattle()),SLOT(createBattleScene()));
    QObject::connect(s,SIGNAL(endBattleEvolution()),SLOT(createEvolutionScene()));
    QObject::connect(s,SIGNAL(endBattleLearnAttaque(QString,bool)),SLOT(createLearnAttaqueScene(QString,bool)));
}
//----------------------------------------------------------------------
void MainWindowsPoke::createEvolutionScene(){
    EvolutionScene* s = new EvolutionScene(*you);
    delete this->view->scene();                             //supprime la vielle scene
    this->view->setScene(s );

    QObject::connect(s,SIGNAL(end()),SLOT(createBattleScene()));
}
//----------------------------------------------------------------------
void MainWindowsPoke::createLearnAttaqueScene(QString nomAttaque, bool needEvolution){
    LearnAttaqueScene* s = new LearnAttaqueScene(*you,nomAttaque,needEvolution);
    delete this->view->scene();                             //supprime la vielle scene
    this->view->setScene(s );

    QObject::connect(s,SIGNAL(end()),SLOT(createBattleScene()));
    QObject::connect(s,SIGNAL(endNeedEvolution()),SLOT(createEvolutionScene()));
    QObject::connect(s,SIGNAL(endNeedLearnAttaque(QString,bool)),SLOT(createLearnAttaqueScene(QString,bool)));
}
