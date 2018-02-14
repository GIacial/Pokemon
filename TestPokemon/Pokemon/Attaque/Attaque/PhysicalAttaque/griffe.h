#ifndef GRIFFE_H
#define GRIFFE_H

#include <QObject>
#include "../physicalattaque.h"
namespace Attaque{

class Griffe : public PhysicalAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit Griffe(AbstractPokemon& user);
    virtual ~Griffe() throw ();

signals:

public slots:

private:
    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 40;
};

}
#endif // GRIFFE_H
