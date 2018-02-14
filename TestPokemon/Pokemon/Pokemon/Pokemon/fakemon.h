#ifndef FAKEMON_H
#define FAKEMON_H

#include <QObject>
#include "../abstractpokemon.h"

class Fakemon : public AbstractPokemon
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Fakemon(unsigned int level=1);
    virtual ~Fakemon() throw ();


signals:

public slots:

private:
    static ListApprentissage* getListApprentissage();
};

#endif // FAKEMON_H
