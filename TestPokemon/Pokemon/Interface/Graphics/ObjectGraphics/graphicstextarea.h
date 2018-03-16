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

    void    setText(const QString text);                                            //mets le text dans le buffer de la fenetre

signals:
    void endText();
public slots:
protected:
    //override
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:
    QGraphicsTextItem* text;
    QList<QString*>*   nextText;

    void    afficheNextText();                                                  //affiche le text contenu dans le buffer
};

#endif // GRAPHICSTEXTAREA_H
