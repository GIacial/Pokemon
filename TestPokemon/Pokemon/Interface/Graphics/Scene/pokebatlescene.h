#ifndef POKEBATLESCENE_H
#define POKEBATLESCENE_H

#include <QObject>
#include <QGraphicsScene>

class PokeBatleScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PokeBatleScene(QObject *parent = nullptr);
    ~PokeBatleScene() throw();

signals:

public slots:
};

#endif // POKEBATLESCENE_H
