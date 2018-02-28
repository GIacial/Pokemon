#ifndef DOUXPARFUM_H
#define DOUXPARFUM_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque{
class DouxParfum : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit DouxParfum(PokemonInterface& user);
    virtual ~DouxParfum() throw();

signals:

public slots:
protected:
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  PRECISION = 100;
};
}
#endif // DOUXPARFUM_H
