#ifndef COMBATTESTCONSOLE_H
#define COMBATTESTCONSOLE_H

#include <QObject>
#include "AbstractInterface/abstractcombatinterface.h"

class combatTestConsole : public AbstractCombatInterface
{

    Q_OBJECT
public:
    explicit combatTestConsole(PokemonInterface *y , PokemonInterface *o);
    //destructeur
    virtual ~combatTestConsole() throw();
    //fonction override
     void launchCombat() ;                //lance un combat

signals:

public slots:
     //override
    void afficheTexte(QString m);
    void apprendreAttaque(unsigned int* t);                //veut apprendre une attaque
    void evoluer();                                        //veut evoluer

private:
};

#endif // COMBATTESTCONSOLE_H
