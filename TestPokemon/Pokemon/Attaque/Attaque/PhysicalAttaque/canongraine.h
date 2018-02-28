#ifndef CANONGRAINE_H
#define CANONGRAINE_H

#include <QObject>
#include "../physicalattaque.h"

namespace Attaque {

class CanonGraine : public PhysicalAttaque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CanonGraine(PokemonInterface& user);
    virtual ~CanonGraine() throw ();
signals:

public slots:

private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 80;
};
}
#endif // CANONGRAINE_H
