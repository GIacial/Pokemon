#include "statut_paralysie.h"

Statut_Paralysie::Statut_Paralysie(PokemonInterface &cible) : AbstractStatut("Paralysie",cible)
{

}

Statut_Paralysie::~Statut_Paralysie() throw (){

}

bool Statut_Paralysie::effect(){
    return rand()%100 > COEF_ATT_POSSIBLE;
}

double Statut_Paralysie::getCoefAltVit()const{
    return COEF_ALT_VIT;
}
