#include "flammeche.h"
#include "../../../Type/typefeu.h"

using namespace Attaque;

Flammeche::Flammeche(AbstractPokemon& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypeFeu(),"Flammeche")
{

}

Flammeche::~Flammeche() throw (){

}
