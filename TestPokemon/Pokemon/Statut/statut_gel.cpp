#include "statut_gel.h"

Statut_Gel::Statut_Gel(PokemonInterface &cible) : AbstractStatut("Gel",cible)
{

}

Statut_Gel::~Statut_Gel() throw (){

}

bool Statut_Gel::effect(){
    emit sendMsg(this->getCible().getNom()+" est gelé");
    return false;
}

bool Statut_Gel::isEndOfStatut(){
    bool ok = rand()%100 < COEF_END;
    if(ok){
        emit sendMsg(this->getCible().getNom()+" est dégelé");
    }
    return ok;
}
