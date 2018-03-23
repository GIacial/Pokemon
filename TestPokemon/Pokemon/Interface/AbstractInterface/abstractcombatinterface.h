#ifndef ABSTRACTCOMBATINTERFACE_H
#define ABSTRACTCOMBATINTERFACE_H

#include <QObject>
#include "../../KernelMecanic/km_combat.h"

class AbstractCombatInterface : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCombatInterface(PokemonInterface *y , PokemonInterface *o);
    virtual ~AbstractCombatInterface() throw ();

    //fonction
     virtual void launchCombat() = 0;                //lance un combat
    const KM_Combat& getSystemCombat()const;
    void useAttaque(unsigned int t) throw (OutOfRange_PersonalExeption);        //lance un tour de combat avec you utilisant sa t-ieme attaque

    void win();                                                                 //quand you gagne

signals:

public slots:
    virtual void afficheTexte(QString m) = 0;
    virtual void apprendreAttaque(QString) = 0;                //veut apprendre une attaque
    virtual void evoluer() = 0;                                        //veut evoluer

protected:
    PokemonInterface& getYou();                                        //donne ton poke
private:
    KM_Combat* c;
    PokemonInterface* you;
};

#endif // ABSTRACTCOMBATINTERFACE_H
