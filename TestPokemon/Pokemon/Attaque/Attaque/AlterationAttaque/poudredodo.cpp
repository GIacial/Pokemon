#include "poudredodo.h"
#include "../../../Type/typeplante.h"
#include "../../../Statut/statut_sommeil.h"

using namespace Attaque;

PoudreDodo::PoudreDodo(PokemonInterface& user) : AlterationAttque(user,PRECISION,new TypePlante(),"Poudre Dodo")
{

}

PoudreDodo::~PoudreDodo() throw (){

}

void PoudreDodo::attaqueEffect(PokemonInterface &cible){
    if(!cible.isOneOfMyType(this->getType())){
       cible.setStatut(new Statut_Sommeil(cible));
    }
    else{
        emit sendMsg("Cela est inneficace sur "+cible.getNom());
    }

}
