#include "abstractpokemon.h"




//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::AbstractPokemon(const QString nom,AbstractType* type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse) : QObject()
{
    this->nom = new QString(nom);
    this->pvAct = new int(0.01*basePv);
    this->basePv = new int(basePv);
    this->baseAttP = new int (baseAttP);
    this->baseDefP = new int (baseDefP);
    this->baseAttS = new int (baseAttS);
    this->baseDefS = new int (baseDefS);
    this->baseVitesse = new int (baseVitesse);
    this->level = new int (1);
    this->attaque = new std::vector<AbstractAttaque *>();
    this->statut = NULL;
    this->xpAct = new int(0);
    this->type = type;
}
//-------------------------------------------------------------------------
//------------------------Destructeur--------------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::~AbstractPokemon() throw(){
    delete nom;
    delete pvAct;
    delete basePv;
    delete baseAttP;
    delete baseDefP;
    delete baseAttS;
    delete baseDefS;
    delete baseVitesse;
    delete level;
    for(int i = this->attaque->size() -1; i >= 0 ; i--){
        delete this->attaque->at(i);
        this->attaque->pop_back();
    }
    if(statut != NULL){
        delete statut;
    }
    delete xpAct;
    if(type != NULL){
        delete type;
    }
}

//-------------------------------------------------------------------------
//------------------------fonction-----------------------------------------
//-------------------------------------------------------------------------
int AbstractPokemon::getPvAct()const{
    return *pvAct;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBasePv()const{
    return *basePv;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBaseAttP()const{
    return *baseAttP;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBaseAttS()const{
    return *baseAttS;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBaseDefP()const{
    return *baseDefP;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBaseDefS()const{
    return *baseDefS;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getBaseVitesse()const{
    return *baseVitesse;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getMaxPv()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBasePv()+1;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getAttP()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBaseAttP()+1;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getAttS()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBaseAttS()+1;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getDefP()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBaseDefP()+1;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getDefS()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBaseDefS()+1;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getVitesse()const{
    return (this->getLevel()/MAX_LEVEL)*this->getBaseVitesse()+1;
}
//-------------------------------------------------------------------------
QString AbstractPokemon::getNom()const{
    return *nom;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getLevel()const{
    return *level;
}
//-------------------------------------------------------------------------
void AbstractPokemon::infligerDegat(unsigned int v){
    int& pv = *pvAct;
    pv -= v;
    if(pv <0){
        pv = 0;
    }
}
//--------------------------------------------------------------------------
double AbstractPokemon::getAttCoef(const AbstractType &type)const{
    return this->type->getAttCoef(type);
}
//--------------------------------------------------------------------------
bool AbstractPokemon::isOneOfMyType(const AbstractType &type) const{
    return this->type->isOneofMyType(type);
}
//--------------------------------------------------------------------------
void AbstractPokemon::soigner(unsigned int v){
    int& pv = *pvAct;
    pv+= v;
    int max = this->getMaxPv();
    if(pv > max){
        pv = max;
    }
}
//--------------------------------------------------------------------------
QString AbstractPokemon::getNomAttaque(unsigned int t)const throw(QString){
    if(t< 0 || t >= this->attaque->size()){
        throw QString("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
    }
    return this->attaque->at(i)->getNom();
}
//--------------------------------------------------------------------------
void AbstractPokemon::useAttaque(unsigned int t,AbstractPokemon& cible)const throw(QString){
    if(t< 0 || t >= this->attaque->size()){
        throw QString("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
    }
    return this->attaque->at(i)->use(cible);
}

//--------------------------------------------------------------------------
//-------------------------Protected fonction-------------------------------
//--------------------------------------------------------------------------
void AbstractPokemon::apprendreAttaque(AbstractAttaque *a, unsigned int place) throw (QString){
    if(this->attaque->size() == NB_MAX_ATTAQUE){
        if(place< 0 || place >= this->attaque->size()){
            throw QString("Poke attaque out of range :"+QString::number(place)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
        }
        delete this->attaque->at(place);
        this->attaque->at(place) = this->attaque->at(this->attaque->size()-1);
        this->attaque->pop_back();
    }
    this->attaque->push_back(a);
}
