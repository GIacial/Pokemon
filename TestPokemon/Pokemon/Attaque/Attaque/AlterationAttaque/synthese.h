#ifndef SYNTHESE_H
#define SYNTHESE_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque{

class Synthese : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Synthese(PokemonInterface& user);
    virtual ~Synthese() throw();

signals:

public slots:
protected:
    void attaqueEffect(PokemonInterface& cible);

private:

    //var static
    static constexpr int const&  COEF_SOIN = 1./2.;
};
}
#endif // SYNTHESE_H
