#ifndef BROUILLARD_H
#define BROUILLARD_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque {

class Brouillard : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Brouillard(PokemonInterface& user);
    virtual ~Brouillard() throw ();

signals:

public slots:

protected:
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 100;
};

}
#endif // BROUILLARD_H
