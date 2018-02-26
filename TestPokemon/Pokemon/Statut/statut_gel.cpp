#include "statut_gel.h"

Statut_Gel::Statut_Gel(PokemonInterface &cible) : AbstractStatut("Gel",cible)
{

}

Statut_Gel::~Statut_Gel() throw (){

}

bool Statut_Gel::effect(){
    return false;
}

bool Statut_Gel::isEndOfStatut()const{
    return rand()%100 < COEF_END;
}
