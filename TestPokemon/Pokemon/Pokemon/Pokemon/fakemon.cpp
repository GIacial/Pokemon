#include "fakemon.h"
#include "../../Type/typenormal.h"
#include "../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../Attaque/Attaque/AlterationAttaque/rugissement.h"
#include "../XpCourbe/rapidecourbe.h"
#include "../../Attaque/Attaque/PhysicalAttaque/fouetliane.h"
#include "../../Attaque/Attaque/SpecialAttaque/flammeche.h"
#include "../../Attaque/Attaque/SpecialAttaque/pistoletaeau.h"


using namespace Attaque;

Fakemon::Fakemon(unsigned int level) : AbstractPokemon("Fakemon",new TypeNormal(),60,60,60,60,60,60,new RapideCourbe(10,level),Fakemon::getListApprentissage(),level)
{
    this->apprendreAttaque(new Charge(*this));
    this->apprendreAttaque(new Rugissement(*this));

}

Fakemon::~Fakemon(){

}

ListApprentissage* Fakemon::getListApprentissage(){
    std::vector<CelluleListApprentissage> l;
    l.push_back(CelluleListApprentissage(6,FouetLiane::staticMetaObject));
    l.push_back(CelluleListApprentissage(7,Flammeche::staticMetaObject));
    l.push_back(CelluleListApprentissage(8,PistoletAEau::staticMetaObject));
    return new ListApprentissage(l);
}
