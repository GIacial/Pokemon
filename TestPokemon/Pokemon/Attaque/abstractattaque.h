#ifndef ABSTRACTATTAQUE_H
#define ABSTRACTATTAQUE_H

class AbstractAttaque;
#include <QObject>
#include "../Pokemon/abstractpokemon.h"

class AbstractAttaque : public QObject
{
    Q_OBJECT
public:
     virtual ~AbstractAttaque() throw() = 0;

signals:

public slots:

protected:
    AbstractAttaque();

private:
};

#endif // ABSTRACTATTAQUE_H
