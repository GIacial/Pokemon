#include "bulbizarre.h"
#include "../../../Type/doubletype.h"
#include "../../XpCourbe/rapidecourbe.h"
#include "./herbizarre.h"

//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"
#include "../../../Attaque/Attaque/AlterationAttaque/vampigraine.h"

using namespace Attaque;

//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Bulbizarre::Bulbizarre(unsigned int level) :
    AbstractPokemon("Bulbizarre",new DoubleType(POISON,PLANTE,"Plante Poison"),BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                    ,new RapideCourbe(BASE_XP,level), Bulbizarre::getListApprentissage(),level)
{

}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Bulbizarre::~Bulbizarre() throw(){

}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
AbstractPokemon* Bulbizarre::evolution()const{
    return new Herbizarre(*this);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
bool Bulbizarre::pretEvolution()const{
    return this->getLevel() >= EVO_LEVEL;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

ListApprentissage* Bulbizarre::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(9,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Charge::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Rugissement::staticMetaObject));
    l.push_back(CelluleListApprentissage(7,Vampigraine::staticMetaObject));
    return new ListApprentissage(l);
}
