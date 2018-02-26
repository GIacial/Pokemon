#ifndef ABSTRACTATTAQUEEFFECT_H
#define ABSTRACTATTAQUEEFFECT_H

#include <QObject>
#include "../../kernelobject.h"
namespace AttaqueEffect {
class AbstractAttaqueEffect;
}
#include "../../Pokemon/pokemoninterface.h"
namespace AttaqueEffect{



class AbstractAttaqueEffect : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
    virtual ~AbstractAttaqueEffect() throw() = 0;

    //fonction
    virtual void effect() = 0;                       //applique l'effect de l'attaque

signals:

public slots:

protected:
    explicit AbstractAttaqueEffect(PokemonInterface& target);

    PokemonInterface& getCible();

private:
    PokemonInterface& cible;
};
}
#endif // ABSTRACTATTAQUEEFFECT_H
