#ifndef CHARGE_H
#define CHARGE_H

#include <QObject>
#include "../physicalattaque.h"

class Charge : public PhysicalAttaque
{
    Q_OBJECT
public:
    explicit Charge(AbstractPokemon& user);
    virtual ~Charge() throw ();

protected:
    void attaqueEffect(AbstractPokemon& cible);


signals:

public slots:
};

#endif // CHARGE_H
