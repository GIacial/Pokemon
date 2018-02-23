#ifndef FLAMMECHE_H
#define FLAMMECHE_H

#include <QObject>
#include "../specialattaque.h"

namespace Attaque {


class Flammeche : public SpecialAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit Flammeche(PokemonInterface& user);
    virtual ~Flammeche() throw ();

signals:

public slots:

protected:
    //override
    void attaqueEffect(PokemonInterface& cible);

private:
    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 40;
    static constexpr int const&  CHANCE_BRULURE = 10;
};

}
#endif // FLAMMECHE_H
