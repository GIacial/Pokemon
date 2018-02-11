#include "km_combat.h"

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
KM_Combat::KM_Combat(AbstractPokemon &you, AbstractPokemon &other) : KernelObject(), you(you) , other(other)
{
    QObject::connect(&you,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
    QObject::connect(&other,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
KM_Combat::~KM_Combat() throw (){

}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
void KM_Combat::useAttaque(unsigned int t) throw (QString){
    playOneTurn(t);
}
//---------------------------------------------------------------
bool KM_Combat::allInLife()const{
    return you.isInLife() && other.isInLife();
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
void KM_Combat::playOneTurn(unsigned int t) throw(QString){
    //qui est le plus rapide
    int youVit = this->you.getVitesse();
    int otherVit = this->other.getVitesse();
    youVit += rand()%10;
    otherVit += rand()%10;

    if(youVit >= otherVit){
        this->you.useAttaque(t,other);
        if(other.isInLife()){
            other.useAttaque(0,you);
        }
    }
    else{
        other.useAttaque(0,you);
        if(you.isInLife()){
            you.useAttaque(t,other);
        }
    }

}
