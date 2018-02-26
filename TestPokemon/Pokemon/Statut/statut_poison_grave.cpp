#include "statut_poison_grave.h"

Statut_Poison_Grave::Statut_Poison_Grave(PokemonInterface &cible) : Statut_Poison(cible)
{
    this->tour = new int(0);
}

Statut_Poison_Grave::~Statut_Poison_Grave() throw (){
    delete tour;
}

int Statut_Poison_Grave::calculDegat(int pvMax){
    (*tour)++;
    return (*tour)*COEF_DEG*pvMax;
}
