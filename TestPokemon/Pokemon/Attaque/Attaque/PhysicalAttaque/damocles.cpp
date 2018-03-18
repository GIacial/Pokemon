#include "damocles.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Damocles::Damocles(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Damoclès")
{

}

Damocles::~Damocles() throw (){

}

void Damocles::attaqueEffect(PokemonInterface &cible){
    PhysicalAttaque::attaqueEffect(cible);
    emit sendMsg(this->getUser().getNom() + " prends des degats de recul");
    this->getUser().infligerDegat(this->getAttaque(cible)*COEF_RECUL);
}
