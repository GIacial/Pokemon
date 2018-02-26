#include "vampigraineeffect.h"

using namespace AttaqueEffect;

VampigraineEffect::VampigraineEffect(PokemonInterface& cible,PokemonInterface& user) : AbstractAttaqueEffect(cible),user(user)
{

}

VampigraineEffect::~VampigraineEffect() throw (){

}

void VampigraineEffect::effect(){
    unsigned int degat = 1;
    int pv = this->getCible().getPvAct();
    int d = pv*COEF_DEG;
    if(pv >= d && d > 0){
        degat = d;

    }
    emit sendMsg(user.getNom() + " vampirise la vie de " + this->getCible().getNom());
    this->getCible().infligerDegat(degat);
    this->user.soigner(degat);
}
