#ifndef POKEBATLESCENEKERNEL_H
#define POKEBATLESCENEKERNEL_H

class PokeBatleSceneKernel;

#include <QObject>
#include "../../AbstractInterface/abstractcombatinterface.h"
#include "./pokebatlescene.h"

class PokeBatleSceneKernel : public AbstractCombatInterface
{
    Q_OBJECT
public:
    explicit PokeBatleSceneKernel(PokeBatleScene& interface, PokemonInterface *y, PokemonInterface *o);
    virtual ~PokeBatleSceneKernel() throw ();
    //override
      void launchCombat() ;                //lance un combat

signals:

public slots:
      //override
     void afficheTexte(QString m) ;
     void apprendreAttaque(unsigned int* t) ;                //veut apprendre une attaque
     void evoluer(bool* t) ;                                        //veut evoluer

private:
     PokeBatleScene& interface;
};

#endif // POKEBATLESCENEKERNEL_H
