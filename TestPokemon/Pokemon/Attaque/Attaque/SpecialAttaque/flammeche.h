#ifndef FLAMMECHE_H
#define FLAMMECHE_H

#include <QObject>
#include "../specialattaque.h"

namespace Attaque {


class Flammeche : public SpecialAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit Flammeche(AbstractPokemon& user);
    virtual ~Flammeche() throw ();

signals:

public slots:


private:
    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 40;
};

}
#endif // FLAMMECHE_H
