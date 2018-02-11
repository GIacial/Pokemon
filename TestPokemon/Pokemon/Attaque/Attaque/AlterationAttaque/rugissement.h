#ifndef RUGISSEMENT_H
#define RUGISSEMENT_H

#include <QObject>
#include "../alterationattque.h"

class Rugissement : public AlterationAttque
{
    Q_OBJECT
public:
    explicit Rugissement(AbstractPokemon& user);
    virtual ~Rugissement() throw();

protected:
    void attaqueEffect(AbstractPokemon& cible);

signals:

public slots:
};

#endif // RUGISSEMENT_H
