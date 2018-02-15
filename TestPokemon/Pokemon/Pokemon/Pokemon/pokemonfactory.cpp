#include "pokemonfactory.h"
#include <iostream>
//include poke
#include "./fakemon.h"
#include "./Gen1/allgen1.h"

//-------------------------------------------------------------------
//-----------------------------Constructeur--------------------------
//-------------------------------------------------------------------
PokemonFactory::PokemonFactory() : QObject()
{
    this->listPoke = new QList<QMetaObject> ();
    listPoke->append(Fakemon::staticMetaObject);
    listPoke->append(Bulbizarre::staticMetaObject);
    listPoke->append(Herbizarre::staticMetaObject);
    listPoke->append(Florizarre::staticMetaObject);
    listPoke->append(Salameche::staticMetaObject);
}

//-------------------------------------------------------------------
//------------------------------Destructeur--------------------------
//-------------------------------------------------------------------
PokemonFactory::~PokemonFactory() throw (){
    delete listPoke;
}
//-------------------------------------------------------------------
//------------------------------Fonction-----------------------------
//-------------------------------------------------------------------
PokemonFactory& PokemonFactory::getInstance(){
    static PokemonFactory r;
    return r;
}
//-------------------------------------------------------------------
AbstractPokemon* PokemonFactory::createPoke(unsigned int num , unsigned int lv ) const throw (MetaConstructeurFail_PersonalException){
    AbstractPokemon* p = (AbstractPokemon*)listPoke->at(num).newInstance(Q_ARG(unsigned int,lv));
    if(p == NULL){
        throw MetaConstructeurFail_PersonalException("tu as oublier un Q_INVOKE pour "+QString(listPoke->at(num).className()));
    }
    return p;
}
//-------------------------------------------------------------------
AbstractPokemon* PokemonFactory::createRandomPokemon(unsigned int lv) const throw (MetaConstructeurFail_PersonalException){
    return this->createPoke(rand()%listPoke->size(),lv);

}
//-------------------------------------------------------------------
unsigned int PokemonFactory::getNbPoke()const{
    return this->listPoke->size();
}
