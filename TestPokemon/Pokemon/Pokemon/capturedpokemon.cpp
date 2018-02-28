#include "capturedpokemon.h"

#include <iostream>
using  namespace std;
//----------------------------------------------------------------------------------------
//----------constructeur------------------------------------------------------------------
//----------------------------------------------------------------------------------------
CapturedPokemon::CapturedPokemon(AbstractPokemon *p) : PokemonInterface()
{
    this->poke = p;
    this->connectAllSignaux();
}
//----------------------------------------------------------------------------------------
//------------Destrcuteur-----------------------------------------------------------------
//----------------------------------------------------------------------------------------
CapturedPokemon::~CapturedPokemon() throw(){
    delete poke;
}
//----------------------------------------------------------------------------------------
//------------override public-------------------------------------------------------------
//----------------------------------------------------------------------------------------
int CapturedPokemon::getPvAct()const{
    return this->poke->getPvAct();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBasePv()const{
    return this->poke->getBasePv();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBaseAttP()const{
    return this->poke->getBaseAttP();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBaseAttS()const{
    return this->poke->getBaseAttS();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBaseDefP()const{
    return this->poke->getBaseDefP();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBaseDefS()const{
    return this->poke->getBaseDefS();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getBaseVitesse()const{
    return this->poke->getBaseVitesse();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getMaxPv()const{
    return this->poke->getMaxPv();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getAttP()const{
    return this->poke->getAttP();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getAttS()const{
    return this->poke->getAttS();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getDefP()const{
    return this->poke->getDefP();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getDefS()const{
    return this->poke->getDefS();
}
//----------------------------------------------------------------------------------------
int CapturedPokemon::getVitesse()const{
    return this->poke->getVitesse();
}
//----------------------------------------------------------------------------------------
QString CapturedPokemon::getNom()const{
    return this->poke->getNom();
}
//----------------------------------------------------------------------------------------
unsigned int CapturedPokemon::getLevel()const{
   return this->poke->getLevel();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::infligerDegat(unsigned int v){
    this->poke->infligerDegat(v);
}
//----------------------------------------------------------------------------------------
double CapturedPokemon::getAttCoef(const AbstractType &type) const{
    return this->poke->getAttCoef(type);
}
//----------------------------------------------------------------------------------------
bool CapturedPokemon::isOneOfMyType(const AbstractType &type) const{
    return this->poke->isOneOfMyType(type);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::soigner(unsigned int v){
    this->poke->soigner(v);
}
//----------------------------------------------------------------------------------------
QString CapturedPokemon::getNomAttaque(unsigned int t) const throw (OutOfRange_PersonalExeption){
    return this->poke->getNomAttaque(t);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::useAttaque(unsigned int t, PokemonInterface &cible) throw (OutOfRange_PersonalExeption){
    this->poke->useAttaque(t,cible);
}
//----------------------------------------------------------------------------------------
bool CapturedPokemon::isInLife()const{
    return this->poke->isInLife();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeAttP(unsigned int nb){
     this->poke->upgradeAttP(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeAttS(unsigned int nb){
     this->poke->upgradeAttS(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeDefP(unsigned int nb){
     this->poke->upgradeDefP(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeDefS(unsigned int nb){
     this->poke->upgradeDefS(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeVit(unsigned int nb){
    this->poke->upgradeVit(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradePrecision(unsigned int nb){
    this->poke->upgradePrecision(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseAttP(unsigned int nb){
     this->poke->decreaseAttP(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseAttS(unsigned int nb){
     this->poke->decreaseAttS(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseDefP(unsigned int nb){
     this->poke->decreaseDefP(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseDefS(unsigned int nb){
     this->poke->decreaseDefS(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseVit(unsigned int nb){
    this->poke->decreaseVit(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreasePrecision(unsigned int nb){
    this->poke->decreasePrecision(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::earnXp(const PokemonInterface &p){
    this->poke->earnXp(p);
}
//----------------------------------------------------------------------------------------
Xp CapturedPokemon::getXp()const{
    return this->poke->getXp();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::soinComplet(){
    this->poke->soinComplet();
}
//----------------------------------------------------------------------------------------
unsigned int CapturedPokemon::getNbAttaque()const{
    return this->poke->getNbAttaque();
}
//----------------------------------------------------------------------------------------
double CapturedPokemon::getPrecision()const{
    return this->poke->getPrecision();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::setStatut(AbstractStatut *newStatut){
    this->poke->setStatut(newStatut);
}
//----------------------------------------------------------------------------------------
Xp CapturedPokemon::getBaseXp()const{
    return this->poke->getXp();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::addAttaqueEffect(AttaqueEffect::AbstractAttaqueEffect *e){
    this->poke->addAttaqueEffect(e);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::finTour(){
    this->poke->finTour();
}
//----------------------------------------------------------------------------------------
bool CapturedPokemon::isUnderAttaqueEffect(const QString className){
    return this->poke->isUnderAttaqueEffect(className);
}
//----------------------------------------------------------------------------------------
double CapturedPokemon::getEsquive()const{
    return this->poke->getEsquive();
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::upgradeEsquive(unsigned int nb){
    return this->poke->upgradeEsquive(nb);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::decreaseEsquive(unsigned int nb){
    return this->poke->decreaseEsquive(nb);
}
//----------------------------------------------------------------------------------------
//---------------------slot---------------------------------------------------------------
//----------------------------------------------------------------------------------------
void CapturedPokemon::slot_apprendreAttaque(unsigned int *t){
    emit veutApprendreAttaque(t);
}
//----------------------------------------------------------------------------------------
void CapturedPokemon::slot_evolution(bool *){
    bool ok = false;
    emit veutEvoluer(&ok);
    cout << "ok cp" << endl;
    if(ok){
        //evolution
        AbstractPokemon* evo = this->poke->evolution();
        if(evo != NULL){
            emit sendMsg (this->poke->getNom() + " évolue en " + evo->getNom());
            delete poke;
            this->poke = evo;
            this->connectAllSignaux();
        }
    }
}
//----------------------------------------------------------------------------------------
//------------------------private---------------------------------------------------------
//----------------------------------------------------------------------------------------

void CapturedPokemon::connectAllSignaux(){
    QObject::connect(poke,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
    QObject::connect(poke,SIGNAL(veutApprendreAttaque(uint*)),this,SLOT(slot_apprendreAttaque(uint*)));
    QObject::connect(poke,SIGNAL(veutEvoluer(bool*)),this,SLOT(slot_evolution(bool*)));
}
