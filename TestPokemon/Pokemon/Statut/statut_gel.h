#ifndef STATUT_GEL_H
#define STATUT_GEL_H

#include <QObject>
#include "./abstractstatut.h"

class Statut_Gel : public AbstractStatut
{
    Q_OBJECT
public:
    explicit Statut_Gel(PokemonInterface& cible);
    virtual ~Statut_Gel() throw();

    //override
    bool effect();                          //applique l'effect du statut
    bool   isEndOfStatut();                //dit si c'est la fin du statut
signals:

public slots:

private:
    static constexpr const double& COEF_END = 1./5.;
};

#endif // STATUT_GEL_H
