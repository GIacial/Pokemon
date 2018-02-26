#ifndef VAMPIGRAINEEFFECT_H
#define VAMPIGRAINEEFFECT_H

#include <QObject>
#include "../abstractattaqueeffect.h"
namespace AttaqueEffect{

class VampigraineEffect : public AbstractAttaqueEffect
{
    Q_OBJECT
public:
    explicit VampigraineEffect(PokemonInterface& cible,PokemonInterface& user);
    virtual ~VampigraineEffect() throw ();

    //override
    void effect() ;                       //applique l'effect de l'attaque
signals:

public slots:

private:
    PokemonInterface& user;

    static constexpr double const&  COEF_DEG = 1./8.;
};

}
#endif // VAMPIGRAINEEFFECT_H
