#include "abstractpokemon.h"




//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::AbstractPokemon(const QString nom,AbstractType* type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse) : QObject()
{
    this->nom = new QString(nom);
    this->pvAct = new int(0.01*basePv);
    this->basePv = new int(basePv);
    this->baseAttP = new int (baseAttP);
    this->baseDefP = new int (baseDefP);
    this->baseAttS = new int (baseAttS);
    this->baseDefS = new int (baseDefS);
    this->baseVitesse = new int (baseVitesse);
    this->level = new int (1);
    this->attaque = new std::vector<AbstractAttaque>();
    this->statut = NULL;
    this->xpAct = new int(0);
    this->type = type;
}
//-------------------------------------------------------------------------
//------------------------Destructeur--------------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::~AbstractPokemon() throw(){

}
