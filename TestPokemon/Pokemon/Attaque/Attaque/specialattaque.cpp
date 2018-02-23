#include "specialattaque.h"

using namespace Attaque;

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
SpecialAttaque::SpecialAttaque(PokemonInterface& user,int precision,int puissance,AbstractType* type,const QString nom) : AbstractAttaque(user,precision,puissance,type,nom)
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
int SpecialAttaque::getAttaque(PokemonInterface &cible) const{
    int res = AbstractAttaque::BASE_PUIS_PAR_LVL*this->getUser().getLevel()+2;
    res *= this->getUser().getAttS()*this->getPuissance();
    res /= (AbstractAttaque::COEF_DEF*cible.getDefS());
    res += 2;
    if(this->isSameTypeUser()){
        res *= AbstractAttaque::COEF_STAB;
    }
    double coef =cible.getAttCoef(this->getType());
    res *= coef;
    if(coef == 0){
        emit sendMsg("C'est inefficace");
    }
    else{
        if(coef <1){
            emit sendMsg("Ce n'est pas trés efficace");
        }
        else{
            if(coef > 1){
                emit sendMsg("C'est super efficace !!");
            }
        }
    }
    return res;
}
//------------------------------------------------------------------
void SpecialAttaque::attaqueEffect(PokemonInterface &cible){
    cible.infligerDegat(this->getAttaque(cible));
}
