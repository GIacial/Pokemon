#include "rugissement.h"
#include "../../../Type/typenormal.h"

Rugissement::Rugissement(AbstractPokemon &user) : AlterationAttque(user,100,new TypeNormal,"Rugissement")
{

}

Rugissement::~Rugissement() throw(){

}

void Rugissement::attaqueEffect(AbstractPokemon &cible){

    cible.decreaseAttP();
}
