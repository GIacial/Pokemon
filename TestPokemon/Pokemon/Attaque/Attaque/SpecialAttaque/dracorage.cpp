#include "dracorage.h"
#include "../../../Type/typedragon.h"

using namespace Attaque;

DracoRage::DracoRage(AbstractPokemon& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypeDragon(),"Draco-Rage")
{

}

DracoRage::~DracoRage() throw (){

}

int DracoRage::getAttaque(AbstractPokemon &) const{
    return DEGAT_FIXE;
}
