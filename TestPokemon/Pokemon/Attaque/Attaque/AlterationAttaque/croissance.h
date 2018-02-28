#ifndef CROISSANCE_H
#define CROISSANCE_H

#include <QObject>
#include "../alterationattque.h"

namespace Attaque{

class Croissance : public AlterationAttque
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Croissance(PokemonInterface& user);
    virtual ~Croissance() throw ();

signals:

public slots:

protected:
    void attaqueEffect(PokemonInterface&);

};
}
#endif // CROISSANCE_H
