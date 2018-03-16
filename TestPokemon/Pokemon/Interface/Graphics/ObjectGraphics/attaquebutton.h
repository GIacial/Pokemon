#ifndef ATTAQUEBUTTON_H
#define ATTAQUEBUTTON_H

#include <QObject>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
#include "../../AbstractInterface/abstractcombatinterface.h"

class AttaqueButton : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit AttaqueButton(AbstractCombatInterface& kernel,unsigned int i,QGraphicsItem *parent = nullptr);
    virtual ~AttaqueButton() throw ();

    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item

signals:

public slots:

protected:
    //override
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:
    AbstractCombatInterface& kernel;
    QGraphicsTextItem* text;
    uint*   attaqueNumber;
};

#endif // ATTAQUEBUTTON_H
