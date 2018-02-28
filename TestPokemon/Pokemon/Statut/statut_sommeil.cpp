#include "statut_sommeil.h"

Statut_Sommeil::Statut_Sommeil(PokemonInterface &cible) : AbstractStatut("Sommeil",cible)
{
    this->tour = new int (0);
}

Statut_Sommeil::~Statut_Sommeil() throw(){
    delete tour;
}

bool Statut_Sommeil::effect(){
    emit sendMsg(this->getCible().getNom()+" dort");
    return false;
}

bool Statut_Sommeil::isEndOfStatut(){
    (*tour)++;
    bool ok = rand()%100 < COEF_END*(*tour);
    if(ok){
        emit sendMsg(this->getCible().getNom() + " se reveille");
    }
    return ok;
}
