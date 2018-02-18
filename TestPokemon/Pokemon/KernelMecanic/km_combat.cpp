#include "km_combat.h"

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
KM_Combat::KM_Combat(AbstractPokemon *you, AbstractPokemon *other) : KernelObject(), you(you) , other(other)
{
    QObject::connect(you,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
    QObject::connect(other,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));

    QObject::connect(you,SIGNAL(veutApprendreAttaque(int*)),this,SLOT(apprendreAttaqueSlot(int*)));
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
KM_Combat::~KM_Combat() throw (){
    //ne delete pas les poke
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
void KM_Combat::useAttaque(unsigned int t) throw (OutOfRange_PersonalExeption){
    playOneTurn(t);
}
//---------------------------------------------------------------
bool KM_Combat::allInLife()const{
    return you->isInLife() && other->isInLife();
}
//---------------------------------------------------------------
QString KM_Combat::getNomCreature(CibleKM_COMBAT c) const{
    if(c == ME){
        return you->getNom();
    }
    return other->getNom();
}
//---------------------------------------------------------------
int KM_Combat::getVieCreature(CibleKM_COMBAT c) const{
    if( c == ME){
        return you->getPvAct();
    }
    return other->getPvAct();
}
//---------------------------------------------------------------
int KM_Combat::getMaxVieCreature(CibleKM_COMBAT c) const{
    if( c == ME){
        return you->getMaxPv();
    }
    return other->getMaxPv();
}
//---------------------------------------------------------------
QString KM_Combat::getNomAttaqueCreature(CibleKM_COMBAT c,unsigned int t) const throw (OutOfRange_PersonalExeption){
    if( c == ME){
        return you->getNomAttaque(t);
    }
    return other->getNomAttaque(t);
}
//---------------------------------------------------------------
int KM_Combat::getLevelCreature(CibleKM_COMBAT c) const{
    if( c == ME){
        return you->getLevel();
    }
    return other->getLevel();
}
//---------------------------------------------------------------
bool KM_Combat::isInLife(CibleKM_COMBAT c) const{
    if( c == ME){
        return you->isInLife();
    }
    return other->isInLife();
}
//---------------------------------------------------------------
void KM_Combat::earnXp(){
    if(you->isInLife()){
        you->earnXp(*other);
    }
}


//---------------------------------------------------------------
//-----------------------slot------------------------------------
//---------------------------------------------------------------
void KM_Combat::apprendreAttaqueSlot(int * t){
    emit PokemonVeutApprendreAttaque(t);
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
void KM_Combat::playOneTurn(unsigned int t) throw(OutOfRange_PersonalExeption){
    //qui est le plus rapide
    int youVit = this->you->getVitesse();
    int otherVit = this->other->getVitesse();
    youVit += rand()%10;
    otherVit += rand()%10;

    if(youVit >= otherVit){
        this->you->useAttaque(t,*other);
        if(other->isInLife()){
            unsigned int x = rand()%(other->getNbAttaque()+2);
            x -= 2;
            if(x> other->getNbAttaque()-1){
                x = other->getNbAttaque()-1;
            }
            other->useAttaque(x,*you);
        }
    }
    else{
        other->useAttaque(0,*you);
        if(you->isInLife()){
            you->useAttaque(t,*other);
        }
    }

}
