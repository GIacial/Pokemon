#include "croissance.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Croissance::Croissance(PokemonInterface& user) : AlterationAttque(user,AbstractAttaque::MAX_PRECISION,new TypeNormal(),"Croissance")
{

}


Croissance::~Croissance() throw (){

}

void Croissance::attaqueEffect(PokemonInterface &){
    this->getUser().upgradeAttP();
    this->getUser().upgradeAttS();
}
