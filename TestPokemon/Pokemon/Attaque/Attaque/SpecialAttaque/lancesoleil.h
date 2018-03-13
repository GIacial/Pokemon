#ifndef LANCESOLEIL_H
#define LANCESOLEIL_H

#include <QObject>
#include "../specialattaque.h"
namespace Attaque {

class LanceSoleil : public SpecialAttaque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit LanceSoleil(PokemonInterface& user);
    virtual ~LanceSoleil() throw ();

    //ovveride
    bool attaqueCharger()const;

signals:

public slots:

protected:
    //override
    void attaqueEffect(PokemonInterface& cible);

private:
    //var static
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 120;

    bool* charge;
};

}
#endif // LANCESOLEIL_H
