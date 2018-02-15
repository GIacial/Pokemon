#include "brouillard.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Brouillard::Brouillard(AbstractPokemon& user) : AlterationAttque(user,PRECISION,new TypeNormal(),"Brouillard")
{

}

Brouillard::~Brouillard() throw(){

}

void Brouillard::attaqueEffect(AbstractPokemon &cible){
    cible.decreasePrecision();
}
