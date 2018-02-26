#include "statalterator.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

StatAlterator::StatAlterator(const AbstractPokemon &user) : KernelObject(),user(user)
{
    this->altAttP = new int(0);
    this->altAttS = new int(0);
    this->altDefP = new int(0);
    this->altDefS = new int(0);
    this->altVit  = new int(0);
    this->precision = new int (0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
StatAlterator::~StatAlterator() throw(){
    delete altAttP;
    delete altAttS;
    delete altDefP;
    delete altDefS;
    delete altVit;
    delete precision;
}
//---------------------------------------------------------------------------
//-------------------------public--------------------------------------------
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltAttP()const{
    return this->getAlteratorCoef(*altAttP);
}
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltAttS()const{
    return this->getAlteratorCoef(*altAttS);
}
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltDefP()const{
    return this->getAlteratorCoef(*altDefP);
}
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltDefS()const{
    return this->getAlteratorCoef(*altDefS);
}
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltVit()const{
    return this->getAlteratorCoef(*altVit);
}
//---------------------------------------------------------------------------
double StatAlterator::getCoefAltPrec()const{
    return this->getAlteratorCoef(*precision);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeAttP(unsigned int nb){
    this->genericUpgrade(altAttP,"son Attaque Physique",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeAttS(unsigned int nb){
    this->genericUpgrade(altAttS,"son Attaque Spéciale",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeDefP(unsigned int nb){
    this->genericUpgrade(altDefP,"sa Défense Physique",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeDefS(unsigned int nb){
    this->genericUpgrade(altDefS,"sa Défense Spéciale",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeVit(unsigned int nb){
    this->genericUpgrade(altVit,"sa vitesse",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::upgradePrec(unsigned int nb){
    this->genericUpgrade(precision,"sa precision",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseAttP(unsigned int nb){
    this->genericDecrease(altAttP,"son Attaque Physique",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseAttS(unsigned int nb){
    this->genericDecrease(altAttS,"son Attaque Spéciale",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseDefP(unsigned int nb){
    this->genericDecrease(altDefP,"sa Défense Physique",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseDefS(unsigned int nb){
    this->genericDecrease(altDefS,"sa Défense Spéciale",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseVit(unsigned int nb){
    this->genericDecrease(altVit,"sa vitesse",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::decreasePrec(unsigned int nb){
    this->genericDecrease(precision,"sa precision",nb);
}
//---------------------------------------------------------------------------
void StatAlterator::resetAlt(){
    *(this->altAttP) = 0;
    *(this->altAttS) = 0;
    *(this->altDefP) = 0;
    *(this->altDefS) = 0;
    *(this->altVit) = 0;
    *(this->precision) = 0;
}
//---------------------------------------------------------------------------
//------------------------private--------------------------------------------
//---------------------------------------------------------------------------
double StatAlterator::getAlteratorCoef(int t)const{
    double r = 1.0;
    if(t != 0){
        if(t<0){
            r = 2.0/(-t+2);
        }
        else{
            r += (0.5*t);
        }
    }
    return r;
}
//---------------------------------------------------------------------------
void StatAlterator::genericUpgrade(int *val, const QString textStat, unsigned int nb){
    if((*val) < MAX_UPGRADE){
        (*val)+= (int)nb;
        if((*val)> MAX_UPGRADE){
            (*val) = MAX_UPGRADE;
        }
         emit sendMsg(this->user.getNom()+" augmente "+textStat);
    }
    else{
        emit sendMsg(this->user.getNom()+" ne peux plus monter "+textStat);
    }
}
//---------------------------------------------------------------------------
void StatAlterator::genericDecrease(int *val, const QString textStat,unsigned int nb){
    if((*val) > MAX_DECREASE){
        (*val)-= (int)nb;
        if((*val)< MAX_DECREASE){
            (*val) = MAX_DECREASE;
        }
         emit sendMsg(this->user.getNom()+" vois diminuer "+textStat);
    }
    else{
        emit sendMsg(this->user.getNom()+" ne peux plus voir diminuer "+textStat);
    }
}
