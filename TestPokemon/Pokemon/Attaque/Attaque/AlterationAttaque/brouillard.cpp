#include "brouillard.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Brouillard::Brouillard(PokemonInterface& user) : AlterationAttque(user,PRECISION,new TypeNormal(),"Brouillard")
{

}

Brouillard::~Brouillard() throw(){

}

void Brouillard::attaqueEffect(PokemonInterface &cible){
    cible.decreasePrecision();
}
