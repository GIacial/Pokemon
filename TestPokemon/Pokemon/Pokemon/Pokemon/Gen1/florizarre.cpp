#include "florizarre.h"

#include "../../XpCourbe/rapidecourbe.h"
#include "../../../Type/doubletype.h"


//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"

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
#include "../../../Attaque/Attaque/SpecialAttaque/lancesoleil.h"


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
                     ,new RapideCourbe(BASE_XP,b.getLevel()),Florizarre::getListApprentissage(),b,b.getLevel())
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
    l.push_back(CelluleListApprentissage(0,Charge::staticMetaObject));
    l.push_back(CelluleListApprentissage(3,Rugissement::staticMetaObject));
    l.push_back(CelluleListApprentissage(7,Vampigraine::staticMetaObject));
    l.push_back(CelluleListApprentissage(9,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(13,PoudreToxik::staticMetaObject));
    l.push_back(CelluleListApprentissage(13,PoudreDodo::staticMetaObject));
    l.push_back(CelluleListApprentissage(15,Belier::staticMetaObject));
    l.push_back(CelluleListApprentissage(20,TrancheHerbe::staticMetaObject));
    l.push_back(CelluleListApprentissage(23,DouxParfum::staticMetaObject));
    l.push_back(CelluleListApprentissage(28,Croissance::staticMetaObject));
    l.push_back(CelluleListApprentissage(31,Damocles::staticMetaObject));
    l.push_back(CelluleListApprentissage(45,Synthese::staticMetaObject));
    l.push_back(CelluleListApprentissage(53,LanceSoleil::staticMetaObject));
    return new ListApprentissage(l);
}
