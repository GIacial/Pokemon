#include "abstractpokemon.h"
#include <iostream>
using namespace Attaque;


//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractPokemon::AbstractPokemon(const QString nom, AbstractType* type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse, AbstractCourbe *xpCour, ListApprentissage *apprentissage, unsigned int level) : PokemonInterface()
{
    this->generalConstructeur(nom,type,basePv,baseAttP,baseDefP,baseAttS,baseDefS,baseVitesse,xpCour,apprentissage,level);
    //apprentissage artifficielle
    if(nextAttaque != NULL){
        while(nextAttaque->isMyLvl(*(this->level))){
            this->apprendreAttaque(this->nextAttaque->getNewAttaque(*this),rand()%NB_MAX_ATTAQUE);                                   //apprendre les attaques en mode random

        }
    }
}
//-------------------------------------------------------------------------
AbstractPokemon::AbstractPokemon(const QString nom, AbstractType* type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse, AbstractCourbe *xpCour, ListApprentissage *apprentissage,const AbstractPokemon& preEvolution, unsigned int level) : PokemonInterface()
{
    this->generalConstructeur(nom,type,basePv,baseAttP,baseDefP,baseAttS,baseDefS,baseVitesse,xpCour,apprentissage,level);

    if(nextAttaque != NULL){
        while(nextAttaque->isMyLvl(*(this->level))){
                //oublie des attaque de bas level
            delete nextAttaque->getNewAttaque(*this);
        }
    }

    //on apprends les attaque de l'ancien
    for(unsigned int i=0 ; i<preEvolution.attaque->size() ; i++){
        AbstractAttaque* nattaque = (AbstractAttaque*)preEvolution.attaque->at(i)->metaObject()->newInstance(Q_ARG(PokemonInterface&,*this));
        if(nattaque == NULL){
            throw MetaConstructeurFail_PersonalException("L'attaque n'a pas pu etre copier "+QString(preEvolution.attaque->at(i)->metaObject()->className()));
        }
        this->apprendreAttaque(nattaque);
    }
}
//-------------------------------------------------------------------------
void AbstractPokemon::generalConstructeur(const QString nom, AbstractType *type, int basePv, int baseAttP, int baseDefP, int baseAttS, int baseDefS, int baseVitesse, AbstractCourbe *xpCour, ListApprentissage *apprentissage, unsigned int level){
    this->xpCourbe = xpCour;
    this->nextAttaque = apprentissage;
    this->nom = new QString(nom);
    this->basePv = new int(MULTBASE*basePv);
    this->baseAttP = new int (MULTBASE*baseAttP);
    this->baseDefP = new int (MULTBASE*baseDefP);
    this->baseAttS = new int (MULTBASE*baseAttS);
    this->baseDefS = new int (MULTBASE*baseDefS);
    this->baseVitesse = new int (MULTBASE*baseVitesse);
    this->level = new unsigned int (level);
    this->attaque = new std::vector<AbstractAttaque *>();
    this->statut = NULL;
    this->xpAct = new Xp(0);
    this->type = type;
    this->alterations = new StatAlterator(*this);
    QObject::connect(alterations,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));

    this->pvAct = new int(this->getMaxPv());

    if(xpCourbe != NULL){
        *xpAct = this->xpCourbe->getPredXp();   //monter en niveau artificielle
    }
    this->effect = new std::vector<AttaqueEffect::AbstractAttaqueEffect*>();
    this->AttaqueToUse = NULL;

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
    this->clearAttaqueEffect();
    delete effect;
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
    if(nextAttaque != NULL){
        delete nextAttaque;
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
    double coefStatut = 1.;
    if(this->statut != NULL){
        coefStatut = this->statut->getCoefAltVit();
    }
    return coefStatut*this->alterations->getCoefAltVit()*((double)this->getLevel()/MAX_LEVEL)*this->getBaseVitesse()+MINSTAT;
}
//-------------------------------------------------------------------------
QString AbstractPokemon::getNom()const{
    return *nom;
}
//-------------------------------------------------------------------------
unsigned int AbstractPokemon::getLevel()const{
    return *level;
}
//-------------------------------------------------------------------------
void AbstractPokemon::infligerDegat(unsigned int v){
    int& pv = *pvAct;
    pv -= v;
    if(pv <0){
        pv = 0;
    }
    emit changedPv(pv);
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
    emit sendMsg(this->getNom()+" se soigne de "+QString::number(v)+" pv");
}
//--------------------------------------------------------------------------
QString AbstractPokemon::getNomAttaque(unsigned int t)const throw(OutOfRange_PersonalExeption){
    if( t >= this->attaque->size()){
        throw OutOfRange_PersonalExeption("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
    }
    return this->attaque->at(t)->getNom();
}
//--------------------------------------------------------------------------
void AbstractPokemon::useAttaque(unsigned int t, PokemonInterface &cible) throw(OutOfRange_PersonalExeption){
    if(!this->isLockAttaque()){
        if( t >= this->attaque->size()){
            throw OutOfRange_PersonalExeption("Poke attaque out of range :"+QString::number(t)+" n'est pas entre 0 et "+QString::number(this->attaque->size()));
        }
        if(this->statutEffect()){
            AbstractAttaque* skill = this->attaque->at(t);
            skill->use(cible);
            if(skill->attaqueCharger()){
                this->AttaqueToUse = skill;
            }
        }
    }
    else{
        //cas attaque chargé
        this->AttaqueToUse->use(cible);
        if(!this->AttaqueToUse->attaqueCharger()){
            this->AttaqueToUse = NULL;
        }
    }

}
//--------------------------------------------------------------------------
bool AbstractPokemon::isInLife()const{
    return this->getPvAct() > 0;
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeAttP(unsigned int nb){
    this->alterations->upgradeAttP(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeAttS(unsigned int nb){
    this->alterations->upgradeAttS(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeDefP(unsigned int nb){
    this->alterations->upgradeDefP(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeDefS(unsigned int nb){
    this->alterations->upgradeDefS(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeVit(unsigned int nb){
    this->alterations->upgradeVit(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseAttP(unsigned int nb){
    this->alterations->decreaseAttP(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseAttS(unsigned int nb){
    this->alterations->decreaseAttS(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseDefP(unsigned int nb){
    this->alterations->decreaseDefP(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseDefS(unsigned int nb){
    this->alterations->decreaseDefS(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseVit(unsigned int nb){
    this->alterations->decreaseVit(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::earnXp(const PokemonInterface &p){
    if(this->getLevel() < MAX_LEVEL){
        Xp xp = (p.getBaseXp()*p.getLevel()/7.0)+1;
        (*xpAct) += xp;
        emit sendMsg(this->getNom() + " gagne "+ QString::number(xp) + " xp");
        //verif monter de niveau
       this->levelUp();
    }

}
//--------------------------------------------------------------------------
Xp AbstractPokemon::getXp()const{
    return *xpAct;
}
//--------------------------------------------------------------------------
void AbstractPokemon::soinComplet(){
    this->soigner((unsigned int)this->getMaxPv());
    this->alterations->resetAlt();
    if(this->statut != NULL){
        delete this->statut;
        this->statut = NULL;
    }
    this->clearAttaqueEffect();
}
//--------------------------------------------------------------------------
unsigned int AbstractPokemon::getNbAttaque()const{
    return this->attaque->size();
}
//--------------------------------------------------------------------------
double AbstractPokemon::getPrecision()const{
    return this->alterations->getCoefAltPrec();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradePrecision(unsigned int nb ){
    this->alterations->upgradePrec(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreasePrecision(unsigned int nb){
    this->alterations->decreasePrec(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::setStatut(AbstractStatut* newStatut){
    if(this->statut == NULL){
        emit sendMsg(this->getNom()+" souffre maintenant de "+ newStatut->getName());
        this->statut = newStatut;
        QObject::connect(newStatut,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
    }
    else{
        delete newStatut;
        emit sendMsg(this->getNom()+" ne peux pas souffrir d'un autre statut");
    }
}
//--------------------------------------------------------------------------
Xp AbstractPokemon::getBaseXp()const{
    return this->xpCourbe->getBase();
}
//--------------------------------------------------------------------------
AbstractPokemon* AbstractPokemon::evolution()const{
    return NULL;
}
//--------------------------------------------------------------------------
void AbstractPokemon::addAttaqueEffect(AttaqueEffect::AbstractAttaqueEffect *e){
    this->effect->push_back(e);
    QObject::connect(e,SIGNAL(sendMsg(QString)),this,SLOT(afficheMsg(QString)));
}
//--------------------------------------------------------------------------
void AbstractPokemon::finTour(){
    if(this->statut != NULL){
        this->statut->effectEndTurn();
    }
    for(unsigned int i = 0 ; i < this->effect->size() ; i++){
        this->effect->at(i)->effect();
    }
}
//--------------------------------------------------------------------------
bool AbstractPokemon::isUnderAttaqueEffect(const QString className){
    bool ok = false;
    for(unsigned int i = 0 ; i < this->effect->size() && !ok ; i++){
        ok = this->effect->at(i)->inherits(className.toStdString().data());
    }
    return ok;
}
//--------------------------------------------------------------------------
double AbstractPokemon::getEsquive()const{
    return this->alterations->getCoefAltEsquive();
}
//--------------------------------------------------------------------------
void AbstractPokemon::upgradeEsquive(unsigned int nb){
    return this->alterations->upgradeEsquive(nb);
}
//--------------------------------------------------------------------------
void AbstractPokemon::decreaseEsquive(unsigned int nb){
    return this->alterations->decreaseEsquive(nb);
}
//--------------------------------------------------------------------------
bool AbstractPokemon::isLockAttaque()const{
    return this->AttaqueToUse != NULL;
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
//--------------------------------------------------------------------------
bool AbstractPokemon::pretEvolution()const{
    return false;
}
//--------------------------------------------------------------------------
//-------------------------private fonction---------------------------------
//--------------------------------------------------------------------------
void AbstractPokemon::levelUp(){
    while(this->xpCourbe->isUpNextPalier(this->getXp())){
        (*level)++;
        emit changedLevel((*level));
        emit sendMsg(this->getNom() + " est maintenant au niveau "+ QString::number(this->getLevel()));
        this->apprendreAttaqueByLevelUp();
    }
    if(this->pretEvolution()){
        emit veutEvoluer(NULL);
    }
    emit changedPvMax(this->getMaxPv());
}
//--------------------------------------------------------------------------
void AbstractPokemon::apprendreAttaqueByLevelUp(){
    while(this->nextAttaque->isMyLvl(this->getLevel())){
           AbstractAttaque* a = this->nextAttaque->getNewAttaque(*this);
        if(this->getNbAttaque() == NB_MAX_ATTAQUE){
            //cas attaque pleine
            emit sendMsg("Plus de place pour apprendre "+ a->getNom());
            unsigned int t = NB_MAX_ATTAQUE+1;
            emit veutApprendreAttaque(&t);
            if(t > NB_MAX_ATTAQUE){
                delete a; //evite la fuite de l'attaque
            }
            else{
                this->apprendreAttaque(a,t);
                emit sendMsg(this->getNom()+" apprends "+ a->getNom());
            }

        }
        else{
            this->apprendreAttaque(a);
            emit sendMsg(this->getNom()+" apprends "+ a->getNom());
        }
    }
}
//--------------------------------------------------------------------------
bool AbstractPokemon::statutEffect(){
    bool t = true;
    if(this->statut != NULL){
        if(!statut->isEndOfStatut()){
            t = statut->effect();
        }
        else{
            delete statut;
            statut = NULL;
        }
    }
    return t;
}
//--------------------------------------------------------------------------
void AbstractPokemon::clearAttaqueEffect(){
    for(unsigned int i = 0; i < this->effect->size() ; i++){
        delete this->effect->at(i);
        this->effect->at(i) = NULL;
    }
    this->effect->clear();
}
