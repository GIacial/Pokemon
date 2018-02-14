#include "bulbizarre.h"
#include "../../../Type/typeplante.h"
#include "../../XpCourbe/rapidecourbe.h"

//attaque
#include "../../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../../Attaque/Attaque/AlterationAttaque/rugissement.h"
using namespace Attaque;


Bulbizarre::Bulbizarre(unsigned int level) :
    AbstractPokemon("Bulbizarre",new TypePlante(),BASE_PV,BASE_ATTP,BASE_DEFP,BASE_ATTS,BASE_DEFS,BASE_VIT
                    ,new RapideCourbe(BASE_XP,level), Bulbizarre::getListApprentissage(),level)
{
    this->apprendreAttaque(new Charge(*this));
    this->apprendreAttaque(new Rugissement(*this));
}

Bulbizarre::~Bulbizarre() throw(){

}

ListApprentissage* Bulbizarre::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(6,FouetLiane::staticMetaObject));
    return new ListApprentissage(l);
}
