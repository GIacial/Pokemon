#ifndef KM_COMBAT_H
#define KM_COMBAT_H

#include <QObject>
#include "../kernelobject.h"
#include "../Pokemon/abstractpokemon.h"

class KM_Combat : public KernelObject
{
    Q_OBJECT
public:
    explicit KM_Combat(AbstractPokemon& you , AbstractPokemon& other);
    virtual ~KM_Combat() throw ();

    void useAttaque(unsigned int t) throw(QString);                                    //lance la t-iem attaque de ton poke
    bool allInLife()const;                                                              //permet de savoir la fin d'un combat

signals:

public slots:

protected:
    void playOneTurn(unsigned int t) throw(QString);                                   //fait un tour de combat

private:
    AbstractPokemon& you;
    AbstractPokemon& other;
};

#endif // KM_COMBAT_H
