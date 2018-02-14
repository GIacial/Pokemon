#include "griffe.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Griffe::Griffe(AbstractPokemon &user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Griffe")
{

}

Griffe::~Griffe() throw(){

}
