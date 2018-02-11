#include "abstractattaque.h"


//-------------------------------------------------------------------------
//--------------------------Constructeur-----------------------------------
//-------------------------------------------------------------------------
AbstractAttaque::AbstractAttaque(AbstractPokemon &user, unsigned int precision, unsigned int puissance, AbstractType *type,const QString nom) : KernelObject() , utilisateur(user)
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
bool AbstractAttaque::toucheLaCible()const{
    return ((unsigned int)rand()%100) <= this->getPrecision();
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
void AbstractAttaque::use(AbstractPokemon &cible){
    emit sendMsg(this->utilisateur.getNom()+" utilise "+this->getNom());
    if(toucheLaCible()){
        this->attaqueEffect(cible);
    }
    else{
        emit sendMsg(this->getUser().getNom()+" a rate son attaque");
    }
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
const AbstractPokemon& AbstractAttaque::getUser()const{
    return this->utilisateur;
}
//-------------------------------------------------------------------------
const AbstractType& AbstractAttaque::getType() const{
    return * this->type;
}
