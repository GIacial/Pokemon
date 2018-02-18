#ifndef DRACORAGE_H
#define DRACORAGE_H

#include <QObject>
#include "../specialattaque.h"
namespace Attaque{
class DracoRage : public SpecialAttaque
{
    Q_OBJECT
public:
     Q_INVOKABLE explicit DracoRage(AbstractPokemon& user);
    virtual ~DracoRage() throw ();

signals:

public slots:

protected://fonction surcharge
    int getAttaque(AbstractPokemon&)const;
private:

    //var static
    static constexpr int const&  DEGAT_FIXE = 40;
    static constexpr int const&  PRECISION = 100;
    static constexpr int const&  PUISSANCE = 0;
};
}
#endif // DRACORAGE_H
