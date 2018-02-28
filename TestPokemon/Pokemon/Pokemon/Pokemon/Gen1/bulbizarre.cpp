#include "bulbizarre.h"
#include "../../../Type/doubletype.h"
#include "../../XpCourbe/rapidecourbe.h"
#include "./herbizarre.h"

//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"
#include "../../../Attaque/Attaque/AlterationAttaque/vampigraine.h"
#include "../../../Attaque/Attaque/AlterationAttaque/poudretoxik.h"
#include "../../../Attaque/Attaque/AlterationAttaque/poudredodo.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/belier.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/trancheherbe.h"
#include "../../../Attaque/Attaque/AlterationAttaque/douxparfum.h"
#include "../../../Attaque/Attaque/AlterationAttaque/croissance.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/damocles.h"
#include "../../../Attaque/Attaque/AlterationAttaque/synthese.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/canongraine.h"

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
    l.push_back(CelluleListApprentissage(0,Charge::staticMetaObject));
    l.push_back(CelluleListApprentissage(0,Rugissement::staticMetaObject));
    l.push_back(CelluleListApprentissage(7,Vampigraine::staticMetaObject));
    l.push_back(CelluleListApprentissage(9,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(13,PoudreToxik::staticMetaObject));
    l.push_back(CelluleListApprentissage(13,PoudreDodo::staticMetaObject));
    l.push_back(CelluleListApprentissage(15,Belier::staticMetaObject));
    l.push_back(CelluleListApprentissage(19,TrancheHerbe::staticMetaObject));
    l.push_back(CelluleListApprentissage(21,DouxParfum::staticMetaObject));
    l.push_back(CelluleListApprentissage(25,Croissance::staticMetaObject));
    l.push_back(CelluleListApprentissage(27,Damocles::staticMetaObject));
    l.push_back(CelluleListApprentissage(33,Synthese::staticMetaObject));
    l.push_back(CelluleListApprentissage(37,CanonGraine::staticMetaObject));
    return new ListApprentissage(l);
}
