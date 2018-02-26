#include "vampigraine.h"
#include "../../../Type/typeplante.h"
#include "../../AttaqueEffect/AttaqueEffect/vampigraineeffect.h"

using namespace Attaque;

Vampigraine::Vampigraine(PokemonInterface &user) : AlterationAttque(user,PRECISION,new TypePlante(),"Vampigraine")
{

}

Vampigraine::~Vampigraine() throw(){

}

void Vampigraine::attaqueEffect(PokemonInterface &cible){
    if(!cible.isOneOfMyType(this->getType()) && !cible.isUnderAttaqueEffect("AttaqueEffect::VampigraineEffect")){
       cible.addAttaqueEffect(new AttaqueEffect::VampigraineEffect(cible,this->getUser()));
       emit sendMsg ("Les graines prennent racines dans "+cible.getNom());
    }
    else{
        emit sendMsg ("Cela n'affecte pas " + cible.getNom());
    }

}
