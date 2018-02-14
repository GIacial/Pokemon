#include "fakemon.h"
#include "../../Type/typenormal.h"
#include "../../Attaque/Attaque/PhysicalAttaque/charge.h"
#include "../../Attaque/Attaque/AlterationAttaque/rugissement.h"
#include "../XpCourbe/rapidecourbe.h"

Fakemon::Fakemon(unsigned int level) : AbstractPokemon("Fakemon",new TypeNormal(),60,60,60,60,60,60,new RapideCourbe(10,level),level)
{
    this->apprendreAttaque(new Charge(*this));
    this->apprendreAttaque(new Rugissement(*this));
}

Fakemon::~Fakemon(){

}
