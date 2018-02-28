#include "canongraine.h"
#include "../../../Type/typeplante.h"

using namespace Attaque;

CanonGraine::CanonGraine(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypePlante(),"Canon Graine")
{

}

CanonGraine::~CanonGraine() throw (){

}
