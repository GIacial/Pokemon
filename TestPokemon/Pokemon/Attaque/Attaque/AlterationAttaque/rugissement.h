#ifndef RUGISSEMENT_H
#define RUGISSEMENT_H

#include <QObject>
#include "../alterationattque.h"
namespace Attaque{

class Rugissement : public AlterationAttque
{
    Q_OBJECT
public:
      Q_INVOKABLE explicit Rugissement(AbstractPokemon& user);
    virtual ~Rugissement() throw();

protected:
    void attaqueEffect(AbstractPokemon& cible);

signals:

public slots:

private:

    //var static
    static constexpr int const&  PRECISION = 100;
};

}
#endif // RUGISSEMENT_H
