#ifndef ABSTRACTATTAQUE_H
#define ABSTRACTATTAQUE_H

class AbstractAttaque;
#include <QObject>
#include "../Pokemon/abstractpokemon.h"
#include "../Pokemon/Type/abstracttype.h"
#include "../kernelobject.h"

class AbstractAttaque : public KernelObject
{
    Q_OBJECT
public://constante
     static constexpr double const&  COEF_STAB = 2.0;
     static constexpr double const&  BASE_PUIS_PAR_LVL = 0.4;
     static constexpr double const&  COEF_DEF = 50;
     //destructeur
     virtual ~AbstractAttaque() throw() = 0;

    //fonction
    void use(AbstractPokemon& cible) ;                  //utilise l'attaque
    unsigned int getPrecision()const;                               //donne la precision de l'attaque
    unsigned int getPuissance()const;                               //donne la puissance de l'attaque

    bool toucheLaCible()const;                                      //true si l'attaque doit toucher
    bool isSameTypeUser()const;                                     //donne si c'est le meme type que l'utilisateur
    QString getNom()const;                                          //donne le nom de l'attaque


signals:

public slots:

protected:
    AbstractAttaque(AbstractPokemon& user, unsigned int precision , unsigned int puissance , AbstractType* type, const QString nom);

    //fonction
    virtual int getAttaque(AbstractPokemon& cible)const = 0;            //donne la puissance de l'attaque théorique de l'attaque(avec prise en compte de la def)
    const AbstractPokemon& getUser()const;                              //donne l'utilisateur
    const AbstractType& getType()const;                                 //donne le type de l'attaque

    virtual void attaqueEffect(AbstractPokemon& cible) = 0;                  //l'effect de l'attaque
private:
    AbstractPokemon& utilisateur;
    unsigned int* precision;
    unsigned int* puissance;
    AbstractType* type;
    QString* nom;
};

#endif // ABSTRACTATTAQUE_H
