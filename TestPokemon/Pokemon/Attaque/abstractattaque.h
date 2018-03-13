#ifndef ABSTRACTATTAQUE_H
#define ABSTRACTATTAQUE_H
namespace Attaque{
class AbstractAttaque;
}
#include <QObject>
#include "../Pokemon/pokemoninterface.h"
#include "../Type/abstracttype.h"
#include "../kernelobject.h"
namespace Attaque{


class AbstractAttaque : public KernelObject
{
    Q_OBJECT
public://constante
     static constexpr double const&  COEF_STAB = 2.0;
     static constexpr double const&  BASE_PUIS_PAR_LVL = 0.4;
     static constexpr double const&  COEF_DEF = 50;
     static constexpr int const&  MAX_PRECISION = 50000;
     //destructeur
     virtual ~AbstractAttaque() throw() = 0;

    //fonction
    void use(PokemonInterface& cible) ;                  //utilise l'attaque
    unsigned int getPrecision()const;                               //donne la precision de l'attaque
    unsigned int getPuissance()const;                               //donne la puissance de l'attaque

    bool toucheLaCible(PokemonInterface &cible)const;                                      //true si l'attaque doit toucher
    bool isSameTypeUser()const;                                     //donne si c'est le meme type que l'utilisateur
    QString getNom()const;                                          //donne le nom de l'attaque
    virtual bool attaqueCharger()const ;                         //dit si l'attaque est chargé ou pas

signals:

public slots:

protected:
    AbstractAttaque(PokemonInterface& user, unsigned int precision , unsigned int puissance , AbstractType* type, const QString nom);

    //fonction
    virtual int getAttaque(PokemonInterface& cible)const = 0;            //donne la puissance de l'attaque théorique de l'attaque(avec prise en compte de la def)
     PokemonInterface& getUser();                              //donne l'utilisateur
      const PokemonInterface& getUser()const;                              //donne l'utilisateur
    const AbstractType& getType()const;                                 //donne le type de l'attaque

    virtual void attaqueEffect(PokemonInterface& cible) = 0;                  //l'effect de l'attaque
private:
    PokemonInterface& utilisateur;
    unsigned int* precision;
    unsigned int* puissance;
    AbstractType* type;
    QString* nom;
};

}//fin namespace

#endif // ABSTRACTATTAQUE_H
