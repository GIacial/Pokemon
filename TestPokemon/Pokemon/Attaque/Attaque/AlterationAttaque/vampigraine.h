#ifndef VAMPIGRAINE_H
#define VAMPIGRAINE_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque {


class Vampigraine : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Vampigraine(PokemonInterface& user);
    virtual ~Vampigraine() throw();


protected:
    void attaqueEffect(PokemonInterface& cible);

signals:

public slots:

private:

    //var static
    static constexpr int const&  PRECISION = 90;
};

}
#endif // VAMPIGRAINE_H
