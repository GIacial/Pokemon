#include "physicalattaque.h"


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
PhysicalAttaque::PhysicalAttaque(AbstractPokemon& user,int precision,int puissance,AbstractType* type , const QString nom) : AbstractAttaque(user,precision,puissance,type,nom)
{

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
PhysicalAttaque::~PhysicalAttaque() throw(){

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
int PhysicalAttaque::getAttaque(AbstractPokemon &cible) const{
    int res = 0;
    res += this->getUser().getAttP();
    if(this->isSameTypeUser()){
        res *= AbstractAttaque::COEF_STAB;
    }   
    res *= cible.getAttCoef(this->getType());
    res -= cible.getDefP();

    if(res <=0){
        res = 1;
    }
    res *= ((double)this->getPuissance()/AbstractAttaque::BASE_PUISSANCE);

    return res;
}
