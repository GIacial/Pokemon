#ifndef ATTAQUEPANEL_H
#define ATTAQUEPANEL_H

#include <QObject>
#include <QGraphicsWidget>

#include "./attaquebutton.h"

class AttaquePanel : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit AttaquePanel(AbstractCombatInterface& kernel,QGraphicsItem *parent = nullptr);
    virtual ~AttaquePanel() throw ();
    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item

signals:

public slots:

private:
    QList<AttaqueButton*>* buttons;
};

#endif // ATTAQUEPANEL_H
