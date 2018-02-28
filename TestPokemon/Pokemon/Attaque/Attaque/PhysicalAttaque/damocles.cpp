#include "damocles.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Damocles::Damocles(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Damoclès")
{

}

Damocles::~Damocles() throw (){

}

void Damocles::attaqueEffect(PokemonInterface &cible){
    this->getUser().infligerDegat(this->getAttaque(cible)*COEF_RECUL);
}
