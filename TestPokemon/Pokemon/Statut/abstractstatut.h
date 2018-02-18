#ifndef ABSTRACTSTATUT_H
#define ABSTRACTSTATUT_H

class AbstractStatut;
#include <QObject>
#include "../Pokemon/abstractpokemon.h"
#include "../kernelobject.h"

class AbstractStatut : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
     virtual ~AbstractStatut() throw () = 0;

    //fonction
    virtual bool effect() = 0;                          //applique l'effect du statut
    QString getName()const;                             //donne le nom du statut

signals:

public slots:

protected:
    //constructeur
     AbstractStatut(const QString& nom,AbstractPokemon& cible);
     //fonction
     AbstractPokemon& getCible();                   //donne la cible du statut
private:
     AbstractPokemon& cible;
     QString* nom;
};

#endif // ABSTRACTSTATUT_H
