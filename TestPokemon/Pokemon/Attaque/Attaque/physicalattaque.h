#ifndef PHYSICALATTAQUE_H
#define PHYSICALATTAQUE_H

#include <QObject>
#include "../abstractattaque.h"

namespace Attaque{

class PhysicalAttaque : public AbstractAttaque
{
    Q_OBJECT
public:
    virtual ~PhysicalAttaque() throw();

signals:

public slots:

protected:
    //constructeur
    PhysicalAttaque(PokemonInterface &user, int precision, int puissance, AbstractType *type, const QString nom);
    //fonction surcharge
    int getAttaque(PokemonInterface& cible)const;
    void attaqueEffect(PokemonInterface& cible);
};

}
#endif // PHYSICALATTAQUE_H
