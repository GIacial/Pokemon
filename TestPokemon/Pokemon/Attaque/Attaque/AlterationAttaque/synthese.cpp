#include "synthese.h"
#include "../../../Type/typeplante.h"

using namespace Attaque;

Synthese::Synthese(PokemonInterface& user) : AlterationAttque(user,AbstractAttaque::MAX_PRECISION,new TypePlante(),"Synthèse")
{

}

Synthese::~Synthese() throw (){

}

void Synthese::attaqueEffect(PokemonInterface &){
    this->getUser().soigner(COEF_SOIN*this->getUser().getMaxPv());
}
