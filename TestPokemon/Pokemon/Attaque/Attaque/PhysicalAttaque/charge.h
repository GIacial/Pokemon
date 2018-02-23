#ifndef CHARGE_H
#define CHARGE_H

#include <QObject>
#include "../physicalattaque.h"
namespace Attaque{

class Charge : public PhysicalAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit Charge(PokemonInterface& user);
    virtual ~Charge() throw ();



signals:

public slots:


private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 40;
};
}
#endif // CHARGE_H
