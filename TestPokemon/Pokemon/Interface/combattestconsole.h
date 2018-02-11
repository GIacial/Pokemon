#ifndef COMBATTESTCONSOLE_H
#define COMBATTESTCONSOLE_H

#include <QObject>
#include "../kernelobject.h"

class combatTestConsole : public QObject
{
    Q_OBJECT
public:
    explicit combatTestConsole();
    void launchCombat();                //lance un combat

signals:

public slots:
    void afficheTexte(QString m);
};

#endif // COMBATTESTCONSOLE_H
