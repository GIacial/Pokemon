#include "doubletype.h"


//--------------------------------------------------------------------------------------
//---------------------Constructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
DoubleType::DoubleType(TypeCreature f, TypeCreature s, const QString nom) : AbstractType(nom,f)
{
    this->secondType = new TypeCreature(s);
}
//--------------------------------------------------------------------------------------
DoubleType::DoubleType(const AbstractType &f, const AbstractType &s)    : AbstractType(f.getNom()+" "+s.getNom(),f.getType())
{
    this->secondType = new TypeCreature(s.getType());
}
//--------------------------------------------------------------------------------------
//----------------------Destructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
DoubleType::~DoubleType() throw(){
    delete secondType;
}
//--------------------------------------------------------------------------------------
//----------------------Fonction override-----------------------------------------------
//--------------------------------------------------------------------------------------
bool DoubleType::isResistance(const AbstractType &type) const{
    return this->getAttCoef(type)<TableTypes::COEF_NORMAL;
}
//--------------------------------------------------------------------------------------
bool DoubleType::isWeakness(const AbstractType &type) const{
    return this->getAttCoef(type)>TableTypes::COEF_NORMAL;
}
//--------------------------------------------------------------------------------------
double DoubleType::getAttCoef(const AbstractType &att) const{
    return (AbstractType::getAttCoef(att) *TableTypes::getAttMultiplier(*secondType,att.getType()));
}
//--------------------------------------------------------------------------------------
bool DoubleType::isOneofMyType(const AbstractType &att) const{
    return this->getType() == att.getType() || *(this->secondType) == att.getType();
}
