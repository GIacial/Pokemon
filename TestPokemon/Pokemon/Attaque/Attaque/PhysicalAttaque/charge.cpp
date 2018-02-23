#include "charge.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Charge::Charge(PokemonInterface &user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Charge")
{

}

Charge::~Charge() throw(){

}

