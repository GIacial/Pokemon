#include "douxparfum.h"
#include "../../../Type/typenormal.h"

using namespace Attaque;

DouxParfum::DouxParfum(PokemonInterface& user) : AlterationAttque(user,PRECISION,new TypeNormal(),"Doux Parfum")
{

}

DouxParfum::~DouxParfum() throw (){

}

void DouxParfum::attaqueEffect(PokemonInterface &cible){
    cible.decreaseEsquive(2);
}
