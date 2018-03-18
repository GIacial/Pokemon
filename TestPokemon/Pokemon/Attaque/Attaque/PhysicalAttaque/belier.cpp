#include "belier.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

Belier::Belier(PokemonInterface& user) : PhysicalAttaque(user,PRECISION,PUISSANCE,new TypeNormal(),"Bélier")
{

}

Belier::~Belier() throw(){

}

void Belier::attaqueEffect(PokemonInterface &cible){
    PhysicalAttaque::attaqueEffect(cible);
    emit sendMsg(this->getUser().getNom() + " prends des degats de recul");
    this->getUser().infligerDegat(COEF_RECUL * this->getAttaque(cible));
}
