#ifndef PANELLEARNATTAQUE_H
#define PANELLEARNATTAQUE_H

#include <QGraphicsWidget>
#include "../../../Pokemon/pokemoninterface.h"

class PanelLearnAttaque : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit PanelLearnAttaque(PokemonInterface &you, QString nomAttaque, QGraphicsWidget* parent= 0);
    virtual ~PanelLearnAttaque() throw ();
    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item
signals:
public slots:
    void end_slot();
};

#endif // PANELLEARNATTAQUE_H
