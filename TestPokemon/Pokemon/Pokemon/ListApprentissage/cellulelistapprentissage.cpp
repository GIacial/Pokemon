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
AbstractAttaque* CelluleListApprentissage::createInstanceAttaque(AbstractPokemon& user)const{
    return (AbstractAttaque*)this->attaque.newInstance(Q_ARG(AbstractPokemon&,user));
}
//----------------------------------------------------------------------------------------------------
bool CelluleListApprentissage::isMyLevel(unsigned int lv) const{
    return lv == (*lvl);
}
