#include "salameche.h"

#include "../../XpCourbe/rapidecourbe.h"
#include "../../../Type/typefeu.h"


//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/griffe.h"
#include "../../../Attaque/Attaque/SpecialAttaque/flammeche.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"
#include "../../../Attaque/Attaque/AlterationAttaque/brouillard.h"

using namespace Attaque;

//--------------------------------------------------------------------------------------------------
//-----------------------------------constructeur---------------------------------------------------
//--------------------------------------------------------------------------------------------------
Salameche::Salameche(unsigned int level) :
    AbstractPokemon("Salameche",new TypeFeu(),
                    BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                    ,new RapideCourbe(BASE_XP,level),Salameche::getListApprentissage(),level)
{

}
//--------------------------------------------------------------------------------------------------
//------------------------------------Destructeur---------------------------------------------------
//--------------------------------------------------------------------------------------------------
Salameche::~Salameche() throw(){

}
//--------------------------------------------------------------------------------------------------
//-----------------------------------fonction-------------------------------------------------------
//--------------------------------------------------------------------------------------------------

ListApprentissage* Salameche::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(7,Flammeche::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Griffe::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Rugissement::staticMetaObject));
    l.push_back(CelluleListApprentissage(10,Brouillard::staticMetaObject));
    return new ListApprentissage(l);
}
