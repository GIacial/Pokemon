#include "abstractcombatinterface.h"

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------

AbstractCombatInterface::AbstractCombatInterface(PokemonInterface*y , PokemonInterface* o) : QObject()
{
    this->c = new KM_Combat(y,o);
    QObject::connect(c,SIGNAL(sendMsg(QString)),this,SLOT(afficheTexte(QString)));
    QObject::connect(c,SIGNAL(PokemonVeutApprendreAttaque(unsigned int*)),this,SLOT(apprendreAttaque(unsigned int*)));
    QObject::connect(c,SIGNAL(PokemonVeutEvoluer(bool*)),this,SLOT(evoluer(bool*)));
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
