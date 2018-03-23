#include "abstractcombatinterface.h"

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------

AbstractCombatInterface::AbstractCombatInterface(PokemonInterface*y , PokemonInterface* o) : QObject()
{
    this->c = new KM_Combat(y,o);
    you = y;
    QObject::connect(c,SIGNAL(sendMsg(QString)),this,SLOT(afficheTexte(QString)));
    QObject::connect(c,SIGNAL(PokemonVeutApprendreAttaque(QString)),this,SLOT(apprendreAttaque(QString)));
    QObject::connect(c,SIGNAL(PokemonVeutEvoluer()),this,SLOT(evoluer()));
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------

AbstractCombatInterface::~AbstractCombatInterface() throw(){
    delete c;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
const KM_Combat& AbstractCombatInterface::getSystemCombat()const{
    return *c;
}
//------------------------------------------------------------------
void AbstractCombatInterface::useAttaque(unsigned int t) throw(OutOfRange_PersonalExeption){
    this->c->useAttaque(t);
}
//------------------------------------------------------------------
void AbstractCombatInterface::win(){
    this->c->earnXp();
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
PokemonInterface& AbstractCombatInterface::getYou(){
    return *you;
}
