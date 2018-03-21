#ifndef GRAPHICSGIF_H
#define GRAPHICSGIF_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QGraphicsWidget>

class GraphicsGif : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit GraphicsGif(QString adr, QGraphicsItem *parent = nullptr);

    virtual ~GraphicsGif() throw ();

    //override
    QRectF boundingRect()const;


signals:
    void clicked();                                 //emit quand on clique desus
public slots:
    void changedFrame(QRect);
protected:
    //override
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private :
    QMovie* gif;
    QGraphicsPixmapItem* img;
};

#endif // GRAPHICSGIF_H
