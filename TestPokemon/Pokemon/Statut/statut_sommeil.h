#ifndef STATUT_SOMMEIL_H
#define STATUT_SOMMEIL_H

#include <QObject>
#include "abstractstatut.h"

class Statut_Sommeil : public AbstractStatut
{
    Q_OBJECT
public:
    explicit Statut_Sommeil(PokemonInterface& cible);
    virtual ~Statut_Sommeil() throw ();
    //override
    bool effect();                          //applique l'effect du statut
    bool   isEndOfStatut();                //dit si c'est la fin du statut
signals:

public slots:

private:
    static constexpr const double& COEF_END = 1./3.;
    int* tour;
};

#endif // STATUT_SOMMEIL_H
