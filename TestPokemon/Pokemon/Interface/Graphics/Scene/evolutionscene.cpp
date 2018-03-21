#include "evolutionscene.h"


EvolutionScene::EvolutionScene(PokemonInterface &you, QObject *parent) : QGraphicsScene(parent),you(you)
{
    this->setBackgroundBrush(QBrush(QColor(180,180,180)));
    this->setSceneRect(0,0,300,300);

    this->next = NULL;

    this->pred = new GraphicsGif("../Image/Gif/Face/"+you.getNom()+".gif");
    this->addItem(pred);
    pred->setPos(this->sceneRect().width()/2 - pred->boundingRect().width()/2,this->sceneRect().height()/2 - pred->boundingRect().height()/2);

    this->text = new GraphicsTextArea(this->sceneRect().width(),HAUTEUR_TEXT_POURCENTAGE*this->sceneRect().height());
    this->addItem(text);
    this->text->setPos(0,(1-HAUTEUR_TEXT_POURCENTAGE)*this->sceneRect().height());
    text->setText(you.getNom() + " veut evoluer ...");

    this->animation = new QPropertyAnimation(pred,"pos");
    this->animation->setStartValue(pred->pos());
    QPointF end  (-this->pred->boundingRect().width()*1.5,pred->pos().y());
    this->animation->setEndValue(end);
    this->animation->setDuration(2000);

    this->endAnimation = new QPropertyAnimation();
    this->endAnimation->setStartValue(end);
    this->endAnimation->setEndValue(pred->pos());
    this->endAnimation->setDuration(2000);

    QObject::connect(text,SIGNAL(endText()),SLOT(start()));
    QObject::connect(pred,SIGNAL(clicked()),SLOT(stop()));
    QObject::connect(animation,SIGNAL(finished()),SLOT(evolution()));
    QObject::connect(endAnimation,SIGNAL(finished()),SLOT(endEvolution()));

}

EvolutionScene::~EvolutionScene() throw (){
    delete pred;
    delete text;
    delete animation;
    delete endAnimation;
    if(next != NULL){
        delete next;
    }
}

void EvolutionScene::stop(){
    QObject::disconnect(animation,SIGNAL(finished()),this,SLOT(evolution()));
    this->animation->stop();
    this->endEvolution();
}

void EvolutionScene::evolution(){
    you.makeEvolution();

    this->next = new GraphicsGif("../Image/Gif/Face/"+you.getNom()+".gif");
    this->addItem(next);
    this->next->setPos(this->pred->pos());

    this->endAnimation->setTargetObject(next);
    this->endAnimation->setPropertyName("pos");
    this->endAnimation->start();
}

void EvolutionScene::start(){
    this->animation->start();
}

void EvolutionScene::endEvolution(){
    emit end();
}
