#include "abstractstatut.h"



//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractStatut::AbstractStatut(const QString &nom, PokemonInterface &cible) : KernelObject() , cible(cible)
{
    this->nom = new QString(nom);
}
//-------------------------------------------------------------------------
//------------------------Destructeur--------------------------------------
//-------------------------------------------------------------------------
AbstractStatut::~AbstractStatut() throw(){
    delete nom;
}
//-------------------------------------------------------------------------
//------------------------Public fonction----------------------------------
//-------------------------------------------------------------------------
QString AbstractStatut::getName()const{
    return *(this->nom);
}
//-------------------------------------------------------------------------
double AbstractStatut::getCoefAltVit()const{
    return 1.;
}
//-------------------------------------------------------------------------
bool AbstractStatut::isEndOfStatut()const{
    return false;
}
//-------------------------------------------------------------------------
//------------------------Protected fonction-------------------------------
//-------------------------------------------------------------------------
PokemonInterface &AbstractStatut::getCible(){
    return cible;
}
