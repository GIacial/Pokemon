#ifndef STATUT_PARALYSIE_H
#define STATUT_PARALYSIE_H

#include <QObject>
#include "abstractstatut.h"

class Statut_Paralysie : public AbstractStatut
{
    Q_OBJECT
public:
    explicit Statut_Paralysie(PokemonInterface& cible);
    virtual ~Statut_Paralysie() throw ();
    //override
    bool effect();
    double getCoefAltVit()const;                //donne le coef de reduction de la vitesse

signals:

public slots:

private:
    static constexpr const double& COEF_ATT_POSSIBLE = 1./4.;
    static constexpr const double& COEF_ALT_VIT = 1./4.;
};

#endif // STATUT_PARALYSIE_H
