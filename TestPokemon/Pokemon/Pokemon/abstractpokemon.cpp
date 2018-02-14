#include "abstractpokemon.h"




//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::AbstractPokemon(const QString nom, AbstractType* type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse, AbstractCourbe *xpCour, int level) : KernelObject()
{
    this->xpCourbe = xpCour;
    this->nom = new QString(nom);
    this->basePv = new int(MULTBASE*basePv);
    this->baseAttP = new int (MULTBASE*baseAttP);
    this->baseDefP = new int (MULTBASE*baseDefP);
    this->baseAttS = new int (MULTBASE*baseAttS);
    this->baseDefS = new int (MULTBASE*baseDefS);
    this->baseVitesse = new int (MULTBASE*baseVitesse);
    this->level = new int (level);
    this->attaque = new std::vector<AbstractAttaque *>();
    this->statut = NULL;
    this->xpAct = new int(0);
    this->type = type;
    this->alterations = new StatAlterator(*this);
    QObject::connect(alterations,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));

    this->pvAct = new int(this->getMaxPv());
    if(xpCourbe != NULL){
        *xpAct = this->xpCourbe->getPredXp();   //monter en niveau artificielle
    }
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
    delete alterations;
    if(xpCourbe != NULL){
        delete xpCourbe;
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
    return ((double)this->getLevel()/MAX_LEVEL)*this->getBasePv()+MIN_PV+this->getLevel();
}
//-------------------------------------------------------------------------
int AbstractPokemon::getAttP()const{
    return this->alterations->getCoefAltAttP()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseAttP()+MINSTAT;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getAttS()const{
    return this->alterations->getCoefAltAttS()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseAttS()+MINSTAT;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getDefP()const{
    return this->alterations->getCoefAltDefP()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseDefP()+MINSTAT;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getDefS()const{
    return this->alterations->getCoefAltDefS()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseDefS()+MINSTAT;
}
//-------------------------------------------------------------------------
int AbstractPokemon::getVitesse()const{
    return this->alterations->getCoefAltVit()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseVitesse()+MINSTAT;
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
    emit sendMsg(this->getNom()+" a subi "+QString::number(v)+" de degats");
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
QString AbstractPokemon::getNomAttaque(unsigned int t)const throw(OutOfRange_PersonalExeption){
    if( t >= this->attaque->size()){
        throw OutOfRange_PersonalExeption("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
    }
    return this->attaque->at(t)->getNom();
}
//--------------------------------------------------------------------------
void AbstractPokemon::useAttaque(unsigned int t,AbstractPokemon& cible) throw(OutOfRange_PersonalExeption){
    if( t >= this->attaque->size()){
        throw OutOfRange_PersonalExeption("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
    }
    this->attaque->at(t)->use(cible);
}
//--------------------------------------------------------------------------
bool AbstractPokemon::isInLife()const{
    return this->getPvAct() > 0;
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeAttP(){
    this->alterations->upgradeAttP();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeAttS(){
    this->alterations->upgradeAttS();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeDefP(){
    this->alterations->upgradeDefP();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeDefS(){
    this->alterations->upgradeDefS();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeVit(){
    this->alterations->upgradeVit();
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseAttP(){
    this->alterations->decreaseAttP();
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseAttS(){
    this->alterations->decreaseAttS();
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseDefP(){
    this->alterations->decreaseDefP();
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseDefS(){
    this->alterations->decreaseDefS();
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseVit(){
    this->alterations->decreaseVit();
}
//--------------------------------------------------------------------------
void AbstractPokemon::earnXp(const AbstractPokemon &p){
    int xp = (p.xpCourbe->getBase()*p.getLevel()/7.0)+1;
    (*xpAct) += xp;
    emit sendMsg(this->getNom() + " gagne "+ QString::number(xp) + " xp");
    //verif monter de niveau
    while(this->xpCourbe->isUpNextPalier(this->getXp())){
        (*level)++;
        emit sendMsg(this->getNom() + " est maintenant au niveau "+ QString::number(this->getLevel()));
    }
}
//--------------------------------------------------------------------------
int AbstractPokemon::getXp()const{
    return *xpAct;
}
//--------------------------------------------------------------------------
void AbstractPokemon::soinComplet(){
    this->soigner((unsigned int)this->getMaxPv());
}
//--------------------------------------------------------------------------
unsigned int AbstractPokemon::getNbAttaque()const{
    return this->attaque->size();
}
//--------------------------------------------------------------------------
//-------------------------Protected fonction-------------------------------
//--------------------------------------------------------------------------
void AbstractPokemon::apprendreAttaque(AbstractAttaque *a, unsigned int place) throw (QString){
    if(this->attaque->size() == NB_MAX_ATTAQUE){
        if( place >= this->attaque->size()){
            throw QString("Poke attaque out of range :"+QString::number(place)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
        }
        delete this->attaque->at(place);
        this->attaque->at(place) = this->attaque->at(this->attaque->size()-1);
        this->attaque->pop_back();
    }
    this->attaque->push_back(a);
    QObject::connect(a,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
}
