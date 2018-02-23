#include "statut_brulure.h"

Statut_Brulure::Statut_Brulure(PokemonInterface &owner) : AbstractStatut("Brulure",owner)
{

}

Statut_Brulure::~Statut_Brulure() throw (){

}

bool Statut_Brulure::effect(){
    emit sendMsg(this->getCible().getNom() + " souffre de sa brulure");
    this->getCible().infligerDegat(COEF_DEG*this->getCible().getMaxPv());
    return true;
}
