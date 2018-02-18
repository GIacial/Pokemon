#include "grimace.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Grimace::Grimace(AbstractPokemon& user) : AlterationAttque(user,PRECISION,new TypeNormal(),"Grimace")
{

}

Grimace::~Grimace() throw(){

}

void Grimace::attaqueEffect(AbstractPokemon &cible){
    cible.decreaseVit(2);
}
