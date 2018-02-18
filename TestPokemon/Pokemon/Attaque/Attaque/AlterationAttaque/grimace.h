#ifndef GRIMACE_H
#define GRIMACE_H

#include <QObject>
#include "../alterationattque.h"
namespace Attaque{
class Grimace : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Grimace(AbstractPokemon& user);
    virtual ~Grimace() throw ();

signals:

public slots:

protected:
    void attaqueEffect(AbstractPokemon& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 100;
};
}
#endif // GRIMACE_H
