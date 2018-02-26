#ifndef STATUT_POISON_H
#define STATUT_POISON_H

#include <QObject>
#include "./abstractstatut.h"

class Statut_Poison : public AbstractStatut
{
    Q_OBJECT
public:
    explicit Statut_Poison(PokemonInterface& cible);
    virtual ~Statut_Poison() throw ();

    //override
    void effectEndTurn();

signals:

public slots:

protected:
    virtual int calculDegat(int pvMax);                          //calcul les degat de poison

private:
    static constexpr const double& COEF_DEG = 1./8.;
};

#endif // STATUT_POISON_H
