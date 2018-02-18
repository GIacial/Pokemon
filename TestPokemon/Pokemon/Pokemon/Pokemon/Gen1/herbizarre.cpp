#include "herbizarre.h"
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
Herbizarre::Herbizarre(unsigned int level) :
    AbstractPokemon("Herbizarre",new DoubleType(POISON,PLANTE,"Plante Poison"),
                    BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                    ,new RapideCourbe(BASE_XP,level),Herbizarre::getListApprentissage(),level)
{

}
//--------------------------------------------------------------------------------------------------
Herbizarre::Herbizarre(const Bulbizarre &b) :
    AbstractPokemon ("Herbizarre",new DoubleType(POISON,PLANTE, "Plante Poison"),
                     BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                     ,new RapideCourbe(BASE_XP,b.getLevel()),Herbizarre::getListApprentissage(),b,b.getLevel())
{

}
//--------------------------------------------------------------------------------------------------
//------------------------------------Destructeur---------------------------------------------------
//--------------------------------------------------------------------------------------------------
Herbizarre::~Herbizarre() throw(){

}
//--------------------------------------------------------------------------------------------------
//-----------------------------------fonction-------------------------------------------------------
//--------------------------------------------------------------------------------------------------

ListApprentissage* Herbizarre::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(9,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Charge::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Rugissement::staticMetaObject));
    return new ListApprentissage(l);
}
