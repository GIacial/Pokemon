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

void PokeBatleSceneKernel::apprendreAttaque(unsigned int *t){
    try{
        for(unsigned int i=0 ; i<this->getSystemCombat().getNbAttaque() ; i++){
           std:: cout << i <<":" <<this->getSystemCombat().getNomAttaqueCreature(CibleKM_COMBAT::ME,i).toStdString() <<" ";
        }
    }
    catch(OutOfRange_PersonalExeption& r){
        std::cerr << "OutofRange :"+r.getMsg().toStdString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Quel attaque a oublie ?" << std::endl;
    std::cin >> (*t);
}
