#ifndef TRANCHEHERBE_H
#define TRANCHEHERBE_H

#include <QObject>
#include "../physicalattaque.h"

namespace Attaque{
class TrancheHerbe : public PhysicalAttaque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TrancheHerbe(PokemonInterface& user);
    virtual ~TrancheHerbe() throw ();

signals:

public slots:


private:

    //var static
    static constexpr int const&  PRECISION = 95;
    static constexpr int const&  PUISSANCE = 55;
};
}
#endif // TRANCHEHERBE_H
