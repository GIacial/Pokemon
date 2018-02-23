#include "fouetliane.h"
#include "../../../Type/typeplante.h"

using namespace Attaque;


FouetLiane::FouetLiane(PokemonInterface&user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypePlante(),"Fouet Lianes")
{

}

FouetLiane::~FouetLiane() throw(){

}


