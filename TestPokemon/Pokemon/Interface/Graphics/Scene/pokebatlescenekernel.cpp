#include "pokebatlescenekernel.h"
#include <iostream>

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

void PokeBatleSceneKernel::evoluer(){
    this->interface.evoluer();
}

void PokeBatleSceneKernel::apprendreAttaque(QString t){
    this->interface.apprendreAttaque(t);
}
