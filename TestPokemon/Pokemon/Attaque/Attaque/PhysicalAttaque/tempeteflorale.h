#ifndef TEMPETEFLORALE_H
#define TEMPETEFLORALE_H

#include <QObject>
#include "../physicalattaque.h"
namespace Attaque {

class TempeteFlorale : public PhysicalAttaque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TempeteFlorale(PokemonInterface& user);
    virtual ~TempeteFlorale() throw ();
signals:

public slots:

private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 90;
};

}
#endif // TEMPETEFLORALE_H
