#ifndef EVOLUTIONSCENE_H
#define EVOLUTIONSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include "../../../Pokemon/pokemoninterface.h"

#include "../ObjectGraphics/graphicsgif.h"
#include "../ObjectGraphics/graphicstextarea.h"


class EvolutionScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit EvolutionScene(PokemonInterface& you,QObject *parent = nullptr);
    virtual ~EvolutionScene() throw ();

signals:
     void end();

public slots:
    void stop();
    void evolution();
    void start();
    void sendEnd();
    void endEvolution();
private:
     PokemonInterface& you;
     GraphicsGif* pred;
     GraphicsGif* next;
     GraphicsTextArea* text;
     QPropertyAnimation* animation;
     QPropertyAnimation* endAnimation;



     static constexpr double const&  HAUTEUR_TEXT_POURCENTAGE = .25;
};

#endif // EVOLUTIONSCENE_H
