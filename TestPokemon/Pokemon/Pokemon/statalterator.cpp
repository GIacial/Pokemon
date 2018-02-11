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
void StatAlterator::upgradeAttP(){
    this->genericUpgrade(altAttP,"son Attaque Physique");
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeAttS(){
    this->genericUpgrade(altAttS,"son Attaque Spéciale");
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeDefP(){
    this->genericUpgrade(altDefP,"sa Défense Physique");
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeDefS(){
    this->genericUpgrade(altDefS,"sa Défense Spéciale");
}
//---------------------------------------------------------------------------
void StatAlterator::upgradeVit(){
    this->genericUpgrade(altVit,"sa vitesse");
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseAttP(){
    this->genericDecrease(altAttP,"son Attaque Physique");
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseAttS(){
    this->genericDecrease(altAttS,"son Attaque Spéciale");
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseDefP(){
    this->genericDecrease(altDefP,"sa Défense Physique");
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseDefS(){
    this->genericDecrease(altDefS,"sa Défense Spéciale");
}
//---------------------------------------------------------------------------
void StatAlterator::decreaseVit(){
    this->genericDecrease(altVit,"sa vitesse");
}
//---------------------------------------------------------------------------
//------------------------private--------------------------------------------
//---------------------------------------------------------------------------
double StatAlterator::getAlteratorCoef(int t)const{
    double r = 1.0;
    if(t != 0){
        if(t<0){
            r = 1.0/(-t+1);
        }
        else{
            r += (0.5*t);
        }
    }
    return r;
}
//---------------------------------------------------------------------------
void StatAlterator::genericUpgrade(int *val, const QString textStat){
    if((*val) < MAX_UPGRADE){
        (*val)++;
         emit sendMsg(this->user.getNom()+" augmente "+textStat);
    }
    else{
        emit sendMsg(this->user.getNom()+" ne peux plus monter "+textStat);
    }
}
//---------------------------------------------------------------------------
void StatAlterator::genericDecrease(int *val, const QString textStat){
    if((*val) > MAX_DECREASE){
        (*val)--;
         emit sendMsg(this->user.getNom()+" vois diminuer "+textStat);
    }
    else{
        emit sendMsg(this->user.getNom()+" ne peux plus voir diminuer "+textStat);
    }
}
