#ifndef BELIER_H
#define BELIER_H

#include <QObject>
#include "../physicalattaque.h"

namespace Attaque{

class Belier : public PhysicalAttaque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Belier(PokemonInterface& user);
    virtual ~Belier() throw();

signals:

public slots:

signals:

public slots:

protected:
    //override
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 85;
    static constexpr int const&  PUISSANCE = 90;
    static constexpr double const&  COEF_RECUL = 1./4.;
};
}
#endif // BELIER_H
