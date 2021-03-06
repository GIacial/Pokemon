#include "abstractattaque.h"

using namespace Attaque;


//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractAttaque::AbstractAttaque(PokemonInterface &user, unsigned int precision, unsigned int puissance, AbstractType *type, const QString nom) : KernelObject() , utilisateur(user)
{
    this->type = type;
    this->precision = new unsigned int(precision);
    this->puissance = new unsigned int (puissance);
    this->nom = new QString(nom);
}
//-------------------------------------------------------------------------
//------------------------Destructeur--------------------------------------
//-------------------------------------------------------------------------
AbstractAttaque::~AbstractAttaque() throw(){
    if(type != NULL){
        delete type;
    }
    delete precision;
    delete puissance;
    delete nom;
}

//-------------------------------------------------------------------------
//------------------------fonction-----------------------------------------
//-------------------------------------------------------------------------
unsigned int AbstractAttaque::getPrecision()const{
    return * precision;
}
//-------------------------------------------------------------------------
unsigned int AbstractAttaque::getPuissance()const{
    return * puissance;
}
//-------------------------------------------------------------------------
bool AbstractAttaque::toucheLaCible(PokemonInterface& cible)const{
    return ((unsigned int)rand()%100)*cible.getEsquive() <= this->getPrecision()*this->utilisateur.getPrecision();
}
//-------------------------------------------------------------------------
bool AbstractAttaque::isSameTypeUser()const{
    return utilisateur.isOneOfMyType(*(this->type));
}
//-------------------------------------------------------------------------
QString AbstractAttaque::getNom()const{
    return * nom;
}
//-------------------------------------------------------------------------
void AbstractAttaque::use(PokemonInterface &cible){
    emit sendMsg(this->utilisateur.getNom()+" utilise "+this->getNom());
    if(toucheLaCible(cible)){
        this->attaqueEffect(cible);
    }
    else{
        emit sendMsg(this->getUser().getNom()+" a rate son attaque");
    }
}
//-------------------------------------------------------------------------
bool AbstractAttaque::attaqueCharger()const{
    return false;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
const PokemonInterface &AbstractAttaque::getUser() const{
    return this->utilisateur;
}
//-------------------------------------------------------------------------
 PokemonInterface &AbstractAttaque::getUser() {
    return this->utilisateur;
}
//-------------------------------------------------------------------------
const AbstractType& AbstractAttaque::getType() const{
    return * this->type;
}
