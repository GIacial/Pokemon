#include "flammeche.h"
#include "../../../Type/typefeu.h"
#include "../../../Statut/statut_brulure.h"

using namespace Attaque;

Flammeche::Flammeche(AbstractPokemon& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypeFeu(),"Flammeche")
{

}

Flammeche::~Flammeche() throw (){

}

void Flammeche::attaqueEffect(AbstractPokemon &cible){
    SpecialAttaque::attaqueEffect(cible);
    if(rand()%100 < CHANCE_BRULURE){
        cible.setStatut(new Statut_Brulure(cible));
    }
}
