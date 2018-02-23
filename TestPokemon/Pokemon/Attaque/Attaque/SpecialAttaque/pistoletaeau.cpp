#include "pistoletaeau.h"
#include "../../../Type/typeeau.h"

using namespace Attaque;

PistoletAEau::PistoletAEau(PokemonInterface& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypeEau(),"Pistolet a Eau")
{

}

PistoletAEau::~PistoletAEau() throw(){

}
