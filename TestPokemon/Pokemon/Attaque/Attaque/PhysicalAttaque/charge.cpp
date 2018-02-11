#include "charge.h"
#include "../../../Type/typenormal.h"

Charge::Charge(AbstractPokemon &user) : PhysicalAttaque(user,100,40,new TypeNormal(),"Charge")
{

}

Charge::~Charge() throw(){

}

void Charge::attaqueEffect(AbstractPokemon &cible){
    cible.infligerDegat(this->getAttaque(cible));
}
