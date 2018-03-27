#include "learnattaquescene.h"


LearnAttaqueScene::LearnAttaqueScene(PokemonInterface& you,QString nomAttaque, bool needEvolution, QObject *parent) : QGraphicsScene(parent),you(you)
{
    this->setBackgroundBrush(QBrush(QColor(180,180,180)));
    this->setSceneRect(0,0,300,300);


    this->needEvolution = new bool(needEvolution);
    this->nomAttak = new QString(nomAttaque);
    this->needLearn = new bool(false);
    this->buttons = new PanelLearnAttaque(you,nomAttaque);
    this->addItem(buttons);
    this->buttons->hide();

    this->text = new GraphicsTextArea(this->sceneRect().width(),this->sceneRect().height()*HAUTEUR_TEXT_POURCENTAGE);
    this->text->setPos(0,this->sceneRect().height()-this->text->boundingRect().height());
    this->addItem(text);
    this->text->setText(you.getNom()+" veut oublier une attaque pour apprendre "+nomAttaque);

    this->img = new GraphicsGif("../Image/Gif/Face/"+you.getNom()+".gif");
    this->addItem(img);
    this->img->setPos(this->sceneRect().width()*0.75-this->img->boundingRect().width()/2,(1-HAUTEUR_TEXT_POURCENTAGE)*this->sceneRect().height()/2-this->img->boundingRect().height()/2);


    QObject::connect(&you,SIGNAL(veutApprendreAttaque(QString)),SLOT(learn_slot(QString)));
    QObject::connect(&you,SIGNAL(sendMsg(QString)),text,SLOT(setText(QString)));
    QObject::connect(text,SIGNAL(endText()),SLOT(begin()));
}

LearnAttaqueScene::~LearnAttaqueScene() throw (){
    delete needEvolution;
    delete nomAttak;
    delete needLearn;
    delete buttons;
    delete text;
    delete img;
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

void LearnAttaqueScene::begin(){
    this->buttons->show();
    QObject::disconnect(text,SIGNAL(endText()),this,SLOT(begin()));
    QObject::connect(text,SIGNAL(endText()),SLOT(end_slot()));
}
