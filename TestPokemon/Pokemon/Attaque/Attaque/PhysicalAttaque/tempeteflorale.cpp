#include "tempeteflorale.h"
#include "../../../Type/typeplante.h"
using namespace Attaque;

TempeteFlorale::TempeteFlorale(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypePlante(),"Tempête Florale")
{

}

TempeteFlorale::~TempeteFlorale() throw (){

}
