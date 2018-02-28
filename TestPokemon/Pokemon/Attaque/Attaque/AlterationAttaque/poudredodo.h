#ifndef POUDREDODO_H
#define POUDREDODO_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque{

class PoudreDodo : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PoudreDodo(PokemonInterface& user);
    virtual ~PoudreDodo() throw ();
signals:

public slots:
protected:
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 75;
};
}
#endif // POUDREDODO_H
