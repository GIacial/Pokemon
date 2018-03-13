#include "lancesoleil.h"

#include "../../../Type/typeplante.h"

using namespace Attaque;

LanceSoleil::LanceSoleil(PokemonInterface& user) : SpecialAttaque(user,PRECISION,PUISSANCE,new TypePlante(),"Lance Soleil")
{
    this->charge = new bool(false);
}

LanceSoleil::~LanceSoleil() throw (){
    delete charge;
}

void LanceSoleil::attaqueEffect(PokemonInterface &cible){
    if(*charge){
        SpecialAttaque::attaqueEffect(cible);
        (*charge) = false;
    }
    else{
        (*charge) = true;
        emit sendMsg(this->getUser().getNom()+" se charge avec la lumiere du soleil");
    }
}

bool LanceSoleil::attaqueCharger()const{
    return *charge;
}
