#ifndef PHYSICALATTAQUE_H
#define PHYSICALATTAQUE_H

#include <QObject>
#include "../abstractattaque.h"

class PhysicalAttaque : public AbstractAttaque
{
    Q_OBJECT
public:
    virtual ~PhysicalAttaque() throw();

signals:

public slots:

protected:
    //constructeur
    PhysicalAttaque(AbstractPokemon &user, int precision, int puissance, AbstractType *type, const QString nom);
    //fonction surcharge
    int getAttaque(AbstractPokemon& cible)const;
};

#endif // PHYSICALATTAQUE_H
