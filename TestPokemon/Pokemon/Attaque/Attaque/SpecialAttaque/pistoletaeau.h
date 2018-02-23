#ifndef PISTOLETAEAU_H
#define PISTOLETAEAU_H

#include <QObject>
#include "../specialattaque.h"

namespace Attaque {

class PistoletAEau : public SpecialAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit PistoletAEau(PokemonInterface& user);
    virtual ~PistoletAEau() throw ();

signals:

public slots:
private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 40;
};
}

#endif // PISTOLETAEAU_H
