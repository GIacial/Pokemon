#include "grimace.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Grimace::Grimace(PokemonInterface& user) : AlterationAttque(user,PRECISION,new TypeNormal(),"Grimace")
{

}

Grimace::~Grimace() throw(){

}

void Grimace::attaqueEffect(PokemonInterface &cible){
    cible.decreaseVit(2);
}
