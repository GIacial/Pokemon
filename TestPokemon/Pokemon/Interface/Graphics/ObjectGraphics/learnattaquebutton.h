#ifndef LEARNATTAQUEBUTTON_H
#define LEARNATTAQUEBUTTON_H

#include <QObject>
#include <QGraphicsWidget>
#include "../../../Pokemon/pokemoninterface.h"

class LearnAttaqueButton : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit LearnAttaqueButton(PokemonInterface& you, uint i, QString nomAttak, QGraphicsWidget *parent = nullptr);
    virtual ~LearnAttaqueButton() throw ();
    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item

signals:
    void cliked();
public slots:
protected:
    //override
    void mousePressEvent(QGraphicsSceneMouseEvent*);
private:
    PokemonInterface& you;
    uint* i;
};

#endif // LEARNATTAQUEBUTTON_H
