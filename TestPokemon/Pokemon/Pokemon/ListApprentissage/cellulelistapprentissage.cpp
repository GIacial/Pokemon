#include "cellulelistapprentissage.h"

using namespace Attaque;
//----------------------------------------------------------------------------------------------------
//----------------------------------Constructeur------------------------------------------------------
//----------------------------------------------------------------------------------------------------
CelluleListApprentissage::CelluleListApprentissage(unsigned int lv, QMetaObject attaque)
{
    this->lvl = new unsigned int (lv);
    this->attaque = attaque;
}
//----------------------------------------------------------------------------------------------------
CelluleListApprentissage::CelluleListApprentissage(const CelluleListApprentissage &c){
    this->lvl = new unsigned int (*(c.lvl));
    this->attaque = c.attaque;
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------Destructeur------------------------------------------------------
//----------------------------------------------------------------------------------------------------
CelluleListApprentissage::~CelluleListApprentissage() throw(){
    delete lvl;
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------Operator---------------------------------------------------------
//----------------------------------------------------------------------------------------------------
CelluleListApprentissage& CelluleListApprentissage::operator = (const CelluleListApprentissage& c){
    if(this != &c){
        *(this->lvl) = *(c.lvl);
        this->attaque = c.attaque;
    }
    return * this;
}
//----------------------------------------------------------------------------------------------------
bool CelluleListApprentissage::operator <(const CelluleListApprentissage& c)const{
    return *(this->lvl) < *(c.lvl);
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------fonction---------------------------------------------------------
//----------------------------------------------------------------------------------------------------
AbstractAttaque* CelluleListApprentissage::createInstanceAttaque(PokemonInterface &user)const throw (MetaConstructeurFail_PersonalException){
    AbstractAttaque* a = (AbstractAttaque*)this->attaque.newInstance(Q_ARG(PokemonInterface&,user));
    if(a == NULL){
        throw MetaConstructeurFail_PersonalException("tu as oublier un Q_INVOKE pour "+QString(attaque.className()));
    }
    return a;
}
//----------------------------------------------------------------------------------------------------
bool CelluleListApprentissage::isMyLevel(unsigned int lv) const{
    return lv >= (*lvl);
}
