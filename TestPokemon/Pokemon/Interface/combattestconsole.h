#ifndef COMBATTESTCONSOLE_H
#define COMBATTESTCONSOLE_H

#include <QObject>
#include "../kernelobject.h"
#include "../KernelMecanic/km_combat.h"

class combatTestConsole : public QObject
{

    Q_OBJECT
public:
    explicit combatTestConsole(AbstractPokemon& y , AbstractPokemon& o);
    //destructeur
    virtual ~combatTestConsole() throw();
    //fonction
    void launchCombat();                //lance un combat

signals:

public slots:
    void afficheTexte(QString m);

private:
    KM_Combat* c;
};

#endif // COMBATTESTCONSOLE_H
