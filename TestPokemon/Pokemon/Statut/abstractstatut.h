#ifndef ABSTRACTSTATUT_H
#define ABSTRACTSTATUT_H

class AbstractStatut;
#include <QObject>
#include "../Pokemon/pokemoninterface.h"
#include "../kernelobject.h"

class AbstractStatut : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
     virtual ~AbstractStatut() throw () = 0;

    //fonction
    virtual bool effect() ;                          //applique l'effect du statut
    virtual void effectEndTurn() ;                   //l'effect de fin de tour
    virtual double getCoefAltVit()const;                //donne le coef de reduction de la vitesse
    virtual bool   isEndOfStatut();                //dit si c'est la fin du statut
    QString getName()const;                             //donne le nom du statut

signals:

public slots:

protected:
    //constructeur
     AbstractStatut(const QString& nom,PokemonInterface& cible);
     //fonction
     PokemonInterface& getCible();                   //donne la cible du statut
private:
     PokemonInterface& cible;
     QString* nom;
};

#endif // ABSTRACTSTATUT_H
