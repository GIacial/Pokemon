#ifndef POUDRETOXIK_H
#define POUDRETOXIK_H

#include <QObject>
#include "../alterationattque.h"
namespace Attaque{
class PoudreToxik : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PoudreToxik(PokemonInterface& user);
    virtual ~PoudreToxik() throw();

signals:

public slots:
protected:
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 75;
};
}
#endif // POUDRETOXIK_H
