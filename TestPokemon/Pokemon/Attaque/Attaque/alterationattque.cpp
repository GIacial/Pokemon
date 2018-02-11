#include "alterationattque.h"

AlterationAttque::AlterationAttque(AbstractPokemon &user, int precision,  AbstractType *type, const QString nom) : AbstractAttaque(user,precision,0,type,nom)
{

}

AlterationAttque::~AlterationAttque() throw(){

}

int AlterationAttque::getAttaque(AbstractPokemon &) const{
    return 0;
}
