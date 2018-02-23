#ifndef FOUETLIANE_H
#define FOUETLIANE_H

#include <QObject>
#include "../physicalattaque.h"
namespace Attaque{

class FouetLiane : public PhysicalAttaque
{
    Q_OBJECT
public:

    //constructeur
       Q_INVOKABLE explicit FouetLiane(PokemonInterface & user);
    //destructeur
    virtual ~FouetLiane() throw ();

signals:

public slots:

private:

    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 45;
};
}
#endif // FOUETLIANE_H
