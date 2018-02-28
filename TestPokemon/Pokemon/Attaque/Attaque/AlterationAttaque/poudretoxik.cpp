#include "poudretoxik.h"
#include "../../../Type/typepoison.h"
#include "../../../Type/typeacier.h"
#include "../../../Statut/statut_poison.h"

using namespace Attaque ;

PoudreToxik::PoudreToxik(PokemonInterface& user) : AlterationAttque(user,PRECISION,new TypePoison(),"Poudre toxik")
{

}

PoudreToxik::~PoudreToxik() throw (){

}

void PoudreToxik::attaqueEffect(PokemonInterface &cible){
    TypeAcier acier;
    if((!cible.isOneOfMyType(this->getType())) && (!cible.isOneOfMyType(acier))){
        cible.setStatut(new Statut_Poison(cible));
    }
    else{
        emit sendMsg("Cela est inneficace sur "+cible.getNom());
    }
}
