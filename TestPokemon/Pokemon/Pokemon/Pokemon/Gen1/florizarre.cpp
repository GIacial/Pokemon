#include "florizarre.h"

#include "../../XpCourbe/rapidecourbe.h"
#include "../../../Type/doubletype.h"


//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"

using namespace Attaque;

//--------------------------------------------------------------------------------------------------
//-----------------------------------constructeur---------------------------------------------------
//--------------------------------------------------------------------------------------------------
Florizarre::Florizarre(unsigned int level) :
    AbstractPokemon("Florizarre",new DoubleType(POISON,PLANTE,"Plante Poison"),
                    BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                    ,new RapideCourbe(BASE_XP,level),Florizarre::getListApprentissage(),level)
{

}
//--------------------------------------------------------------------------------------------------
Florizarre::Florizarre(const Herbizarre &b) :
    AbstractPokemon ("Florizarre",new DoubleType(POISON,PLANTE, "Plante Poison"),
                     BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                     ,new RapideCourbe(BASE_XP,b.getLevel()),Florizarre::getListApprentissage(),b.getLevel())
{

}
//--------------------------------------------------------------------------------------------------
//------------------------------------Destructeur---------------------------------------------------
//--------------------------------------------------------------------------------------------------
Florizarre::~Florizarre() throw(){

}
//--------------------------------------------------------------------------------------------------
//-----------------------------------fonction-------------------------------------------------------
//--------------------------------------------------------------------------------------------------

ListApprentissage* Florizarre::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(9,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Charge::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Rugissement::staticMetaObject));
    return new ListApprentissage(l);
}
