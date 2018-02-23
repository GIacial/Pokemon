#include "dracorage.h"
#include "../../../Type/typedragon.h"

using namespace Attaque;

DracoRage::DracoRage(PokemonInterface& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypeDragon(),"Draco-Rage")
{

}

DracoRage::~DracoRage() throw (){

}

int DracoRage::getAttaque(PokemonInterface &) const{
    return DEGAT_FIXE;
}
