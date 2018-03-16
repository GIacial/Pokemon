#include "pokebatlescenekernel.h"

PokeBatleSceneKernel::PokeBatleSceneKernel(PokeBatleScene& interface,PokemonInterface *y, PokemonInterface *o) : AbstractCombatInterface(y,o),interface(interface)
{

}

PokeBatleSceneKernel::~PokeBatleSceneKernel() throw (){

}

void PokeBatleSceneKernel::launchCombat(){

}

void PokeBatleSceneKernel::afficheTexte(QString m){
    this->interface.afficheTexte(m);
}

void PokeBatleSceneKernel::evoluer(bool *t){
    this->interface.evoluer(t);
}

void PokeBatleSceneKernel::apprendreAttaque(unsigned int *t){
    this->interface.apprendreAttaque(t);
}
