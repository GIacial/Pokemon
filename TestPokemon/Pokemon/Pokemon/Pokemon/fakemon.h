#ifndef FAKEMON_H
#define FAKEMON_H

#include <QObject>
#include "../abstractpokemon.h"

class Fakemon : public AbstractPokemon
{
    Q_OBJECT
public:
    explicit Fakemon(unsigned int level=1);
    virtual ~Fakemon() throw ();

signals:

public slots:
};

#endif // FAKEMON_H
