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

public slots:
    void changedFrame(QRect);

private :
    QMovie* gif;
    QGraphicsPixmapItem* img;
};

#endif // GRAPHICSGIF_H
