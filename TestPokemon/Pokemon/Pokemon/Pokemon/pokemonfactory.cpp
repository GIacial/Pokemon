#include "pokemonfactory.h"

//include poke
#include "./fakemon.h"
#include "./Gen1/bulbizarre.h"

//-------------------------------------------------------------------
//-----------------------------Constructeur--------------------------
//-------------------------------------------------------------------
PokemonFactory::PokemonFactory() : QObject()
{
    this->listPoke = new QList<QMetaObject> ();
    listPoke->append(Fakemon::staticMetaObject);
    listPoke->append(Bulbizarre::staticMetaObject);
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
AbstractPokemon* PokemonFactory::createPoke(unsigned int num , unsigned int lv ) const{
    return (AbstractPokemon*)listPoke->at(num).newInstance(Q_ARG(unsigned int,lv));
}
//-------------------------------------------------------------------
AbstractPokemon* PokemonFactory::createRandomPokemon(unsigned int lv) const{
    return this->createPoke(rand()%listPoke->size(),lv);

}
//-------------------------------------------------------------------
unsigned int PokemonFactory::getNbPoke()const{
    return this->listPoke->size();
}
