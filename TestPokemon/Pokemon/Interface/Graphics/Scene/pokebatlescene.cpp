#include "pokebatlescene.h"

PokeBatleScene::PokeBatleScene(PokemonInterface *y, PokemonInterface *o, QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(158,213,158)));
    this->setSceneRect(0,0,300,300);
    this->kernel = new PokeBatleSceneKernel(*this,y,o);
    this->fin = new bool(false);
    this->needEvolution = new bool(false);
    this->needLearnAttaque = NULL;


    this->youDisplay = new BatleDisplayPokemon(y);
    this->otherDisplay = new BatleDisplayPokemon(o);
    this->textDisplay = new GraphicsTextArea(this->sceneRect().width(),this->sceneRect().height()*HAUTEUR_TEXT_POURCENTAGE);
    this->attaque = new AttaquePanel(*kernel);
    this->otherImg = new GraphicsGif("../Image/Gif/Face/"+o->getNom()+".gif");
    this->youImg = new GraphicsGif("../Image/Gif/Dos/"+y->getNom()+".gif");

    this->addItem(this->youDisplay);
    this->addItem(this->otherDisplay);
    this->addItem(textDisplay);
    this->addItem(attaque);
    this->addItem(otherImg);
    this->addItem(youImg);

    this->textDisplay->setPos(0,this->sceneRect().height()-this->textDisplay->boundingRect().height());
    this->youDisplay->setPos(this->sceneRect().width()-this->youDisplay->boundingRect().width(),this->sceneRect().height()-this->youDisplay->boundingRect().height()-this->textDisplay->boundingRect().height()-1);
    this->attaque->setPos(this->sceneRect().width()-this->attaque->boundingRect().width(),this->textDisplay->pos().y());
    this->attaque->setMinimumHeight(this->textDisplay->boundingRect().height());
    this->attaque->setZValue(1);
    qreal posOtherEmptyZoneX = otherDisplay->pos().x()+otherDisplay->boundingRect().width();
    this->otherImg->setPos(posOtherEmptyZoneX+((this->sceneRect().width()-posOtherEmptyZoneX)/2)-(this->otherImg->boundingRect().width()/2), otherDisplay->pos().y()+otherDisplay->boundingRect().height());
    this->youImg->setPos((this->sceneRect().width()-this->youDisplay->boundingRect().width())/2-this->youImg->boundingRect().width()/2, this->sceneRect().height()-this->textDisplay->boundingRect().height()-this->youImg->boundingRect().height()-10);


    QObject::connect(textDisplay,SIGNAL(endText()),this,SLOT(endTurn()));

    this->kernel->launchCombat();
}

PokeBatleScene::~PokeBatleScene() throw(){
    delete youDisplay;
    delete otherDisplay;
    delete textDisplay;
    delete attaque;
    delete kernel;
    delete fin;
    delete otherImg;
    delete youImg;
    delete needEvolution;
    if(needLearnAttaque != NULL){
        delete needLearnAttaque;
    }
}

void PokeBatleScene::afficheTexte(QString m){
    this->textDisplay->setText(m);
}

void PokeBatleScene::apprendreAttaque(QString t){
    this->afficheTexte(this->kernel->getSystemCombat().getNomCreature(CibleKM_COMBAT::ME) + " veut apprendre "+ t);
    this->needLearnAttaque = new QString(t);
}

void PokeBatleScene::evoluer(){
    *(this->needEvolution) = true;

}

void PokeBatleScene::endTurn(){
    if(*fin){
        if(needLearnAttaque != NULL){
            emit endBattleLearnAttaque(*needLearnAttaque,*needEvolution);
        }
        else{
            if(*needEvolution){
                //lancer la sequence de demande d'evolution
                emit endBattleEvolution();
            }
            else{
                emit endBattle();
            }
        }
    }
    else{
        if(!kernel->getSystemCombat().allInLife()){
            if(this->kernel->getSystemCombat().isInLife(CibleKM_COMBAT::OTHERS)){
                this->textDisplay->setText( "Vous etes mort :(" );
            }
            else{
                this->textDisplay->setText( "Vous avez gagnez :)");
                this->kernel->win();
            }
            *fin = true;
        }
        else{
            this->attaque->show();
        }

    }


}
