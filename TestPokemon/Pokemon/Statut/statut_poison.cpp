#include "statut_poison.h"

Statut_Poison::Statut_Poison(PokemonInterface &cible) : AbstractStatut("Poison",cible)
{

}

Statut_Poison::~Statut_Poison() throw(){

}

void Statut_Poison::effectEndTurn(){
    emit sendMsg(this->getCible().getNom() + " souffre de son empoisonnement");
    this->getCible().infligerDegat(this->calculDegat(this->getCible().getMaxPv()));
}

int Statut_Poison::calculDegat(int pvMax){
    return COEF_DEG*pvMax;
}
