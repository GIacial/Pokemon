#include "charge.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Charge::Charge(AbstractPokemon &user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Charge")
{

}

Charge::~Charge() throw(){

}

