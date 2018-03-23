#include "learnattaquescene.h"

LearnAttaqueScene::LearnAttaqueScene(PokemonInterface& you,QString nomAttaque, bool needEvolution, QObject *parent) : QGraphicsScene(parent),you(you)
{
    this->setBackgroundBrush(QBrush(QColor(180,180,180)));
    this->setSceneRect(0,0,300,300);


    this->needEvolution = new bool(needEvolution);
    this->nomAttak = new QString(nomAttaque);
    this->needLearn = new bool(false);

    this->button = new QList<LearnAttaqueButton*>();
    for(uint i = 0 ; i <= you.getNbAttaque() ; i++){
        LearnAttaqueButton* b = new LearnAttaqueButton(you,i,nomAttaque);
        b->setPos(0,i*b->boundingRect().height());
        this->button->append(b);
        this->addItem(b);
        QObject::connect(b,SIGNAL(cliked()),SLOT(end_slot()));
    }

    QObject::connect(&you,SIGNAL(veutApprendreAttaque(QString)),SLOT(learn_slot(QString)));
}

LearnAttaqueScene::~LearnAttaqueScene() throw (){
    delete needEvolution;
    delete nomAttak;
    delete needLearn;
    for(int i = 0 ; i < button->size() ; i++){
        delete button->at(i);
    }
    delete button;
}

void LearnAttaqueScene::end_slot(){
    if(*needLearn){
        emit endNeedLearnAttaque(*nomAttak,*needEvolution);
    }
    else{
        if(*needEvolution){
            emit endNeedEvolution();
        }
        else{
            emit end();
        }
    }
}

void LearnAttaqueScene::learn_slot(QString a){
    *(this->needLearn) = true;
    *(this->nomAttak) = a;
}

