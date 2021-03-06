#ifndef STATUT_BRULURE_H
#define STATUT_BRULURE_H

#include <QObject>
#include "abstractstatut.h"

class Statut_Brulure : public AbstractStatut
{
    Q_OBJECT
public:
    explicit Statut_Brulure(PokemonInterface& owner);
    virtual ~Statut_Brulure() throw ();

    //override
    void effectEndTurn();

signals:

public slots:

private:
    static constexpr const double& COEF_DEG = 1./16.;
};

#endif // STATUT_BRULURE_H
