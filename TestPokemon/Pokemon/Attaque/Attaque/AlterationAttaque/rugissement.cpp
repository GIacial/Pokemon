#include "rugissement.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;


Rugissement::Rugissement(AbstractPokemon &user) : AlterationAttque(user,PRECISION,new TypeNormal,"Rugissement")
{

}

Rugissement::~Rugissement() throw(){

}

void Rugissement::attaqueEffect(AbstractPokemon &cible){

    cible.decreaseAttP();
}
