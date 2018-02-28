#ifndef DAMOCLES_H
#define DAMOCLES_H

#include <QObject>
#include "../physicalattaque.h"

namespace Attaque{

class Damocles : public PhysicalAttaque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Damocles(PokemonInterface& user);
    virtual ~Damocles() throw ();

signals:

public slots:

protected:
    //override
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 120;
    static constexpr double const&  COEF_RECUL = 1./3.;
};
}
#endif // DAMOCLES_H
