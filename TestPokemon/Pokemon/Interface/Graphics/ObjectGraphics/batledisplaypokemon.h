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

    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item


signals:

public slots:
    void changedLevel(const unsigned int level);                      //met a jour le text de lv

private:
    BarVie* displayLife;
    PokemonInterface* poke;
    QGraphicsTextItem* nom;
    QGraphicsTextItem* lv;


    static constexpr int const&  MARGE = 20;
};

#endif // BATLEDISPLAYPOKEMON_H
