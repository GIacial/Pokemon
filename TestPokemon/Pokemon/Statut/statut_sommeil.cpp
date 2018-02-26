#include "statut_sommeil.h"

Statut_Sommeil::Statut_Sommeil(PokemonInterface &cible) : AbstractStatut("Sommeil",cible)
{
    this->tour = new int (0);
}

Statut_Sommeil::~Statut_Sommeil() throw(){
    delete tour;
}

bool Statut_Sommeil::effect(){
    return false;
}

bool Statut_Sommeil::isEndOfStatut()const{
    (*tour)++;
    return rand()%100 < COEF_END*(*tour);
}
