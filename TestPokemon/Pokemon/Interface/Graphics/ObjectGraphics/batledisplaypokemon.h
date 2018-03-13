#ifndef BATLEDISPLAYPOKEMON_H
#define BATLEDISPLAYPOKEMON_H

#include <QObject>
#include <QGraphicsWidget>
#include "./barvie.h"
#include "../../../Pokemon/pokemoninterface.h"

class BatleDisplayPokemon : public QGraphicsWidget
{
    Q_OBJECT
public:
    //constructeur
    explicit BatleDisplayPokemon(PokemonInterface* poke,QGraphicsItem *parent = nullptr);
    //destructeur
    virtual ~BatleDisplayPokemon() throw ();

signals:

public slots:

private:
    BarVie* displayLife;
    PokemonInterface* poke;
};

#endif // BATLEDISPLAYPOKEMON_H
