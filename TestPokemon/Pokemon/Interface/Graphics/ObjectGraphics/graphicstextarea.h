#ifndef GRAPHICSTEXTAREA_H
#define GRAPHICSTEXTAREA_H

#include <QObject>
#include <QGraphicsWidget>

class GraphicsTextArea : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit GraphicsTextArea(qreal largeur, qreal hauteur ,QGraphicsItem *parent = nullptr);
    virtual ~GraphicsTextArea() throw();

    //override
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item

    void    setText(const QString text);                                            //mets le text dans la fenetre

signals:

public slots:

private:
    QGraphicsTextItem* text;
};

#endif // GRAPHICSTEXTAREA_H
