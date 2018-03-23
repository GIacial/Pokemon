#ifndef LEARNATTAQUESCENE_H
#define LEARNATTAQUESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "../../../Pokemon/pokemoninterface.h"
#include "../ObjectGraphics/learnattaquebutton.h"

class LearnAttaqueScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LearnAttaqueScene(PokemonInterface& you,QString nomAttaque,bool needEvolution,QObject *parent = nullptr);
    virtual ~LearnAttaqueScene() throw ();
signals:
    void end();
    void endNeedEvolution();
    void endNeedLearnAttaque(QString nom,bool needEvolution);
public slots:
    void end_slot();
    void learn_slot(QString a);
private:
    bool* needEvolution;
    bool* needLearn;
    QString* nomAttak;
    PokemonInterface& you;
    QList<LearnAttaqueButton*>* button;
};

#endif // LEARNATTAQUESCENE_H
