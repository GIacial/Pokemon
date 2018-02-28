#include "trancheherbe.h"
#include "../../../Type/typeplante.h"

using namespace Attaque;

TrancheHerbe::TrancheHerbe(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypePlante(),"Tranch'Herbe")
{

}

TrancheHerbe::~TrancheHerbe() throw (){

}
