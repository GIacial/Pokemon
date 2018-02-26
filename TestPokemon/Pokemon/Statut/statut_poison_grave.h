#ifndef STATUT_POISON_GRAVE_H
#define STATUT_POISON_GRAVE_H

#include <QObject>
#include "statut_poison.h"

class Statut_Poison_Grave : public Statut_Poison
{
    Q_OBJECT
public:
    explicit Statut_Poison_Grave(PokemonInterface& cible);
    virtual ~Statut_Poison_Grave() throw ();

signals:

protected:
    //override
     int calculDegat(int pvMax);                          //calcul les degat de poison

public slots:

private:
     int* tour;
     static constexpr const double& COEF_DEG = 1./16.;
};

#endif // STATUT_POISON_GRAVE_H
