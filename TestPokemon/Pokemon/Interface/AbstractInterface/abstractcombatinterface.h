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


signals:

public slots:
    virtual void afficheTexte(QString m) = 0;
    virtual void apprendreAttaque(unsigned int* t) = 0;                //veut apprendre une attaque
    virtual void evoluer(bool* t) = 0;                                        //veut evoluer

protected:
    void win();                                                                 //quand you gagne
private:
    KM_Combat* c;
};

#endif // ABSTRACTCOMBATINTERFACE_H
