#include "rugissement.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;


Rugissement::Rugissement(PokemonInterface &user) : AlterationAttque(user,PRECISION,new TypeNormal,"Rugissement")
{

}

Rugissement::~Rugissement() throw(){

}

void Rugissement::attaqueEffect(PokemonInterface &cible){

    cible.decreaseAttP();
}
