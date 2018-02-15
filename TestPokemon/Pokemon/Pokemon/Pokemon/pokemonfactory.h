#ifndef POKEMONFACTORY_H
#define POKEMONFACTORY_H

#include <QObject>
#include "../abstractpokemon.h"
#include "../../Exeption/metaconstructeurfail_personalexception.h"

class PokemonFactory : public QObject
{
    Q_OBJECT
public:
    //destructeur
     virtual ~PokemonFactory() throw ();

    //fonction
    static PokemonFactory& getInstance();               //donne l'instance de la factory
    AbstractPokemon* createPoke(unsigned int num, unsigned int lv = 1)const throw (MetaConstructeurFail_PersonalException);      //donne une nouvelle instance du num-ieme pokemon
    AbstractPokemon* createRandomPokemon(unsigned int lv = 1)const throw (MetaConstructeurFail_PersonalException);        //donne une nouvelle instance d'un pokemon
    unsigned int    getNbPoke()const;                                       //donne le nombre de pok

signals:

public slots:

protected:
    //constructeur
    PokemonFactory();

private:
    QList<QMetaObject>* listPoke;
};

#endif // POKEMONFACTORY_H
