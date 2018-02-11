#include "specialattaque.h"


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
SpecialAttaque::SpecialAttaque(AbstractPokemon& user,int precision,int puissance,AbstractType* type,const QString nom) : AbstractAttaque(user,precision,puissance,type,nom)
{

}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
SpecialAttaque::~SpecialAttaque() throw(){

}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
int SpecialAttaque::getAttaque(AbstractPokemon &cible) const{
    int res = 0;
    res += this->getUser().getAttS();
    if(this->isSameTypeUser()){
        res *= AbstractAttaque::COEF_STAB;
    }

    res *= cible.getAttCoef(this->getType());
    res -= cible.getDefS();
    if(res <=0){
        res = 1;
    }
    res *= ((double)this->getPuissance()/AbstractAttaque::BASE_PUISSANCE);

    return res;
}
