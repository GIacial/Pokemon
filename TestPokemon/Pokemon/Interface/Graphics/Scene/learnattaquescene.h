#ifndef LEARNATTAQUESCENE_H
#define LEARNATTAQUESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "../../../Pokemon/pokemoninterface.h"
#include "../ObjectGraphics/panellearnattaque.h"
#include "../ObjectGraphics/graphicstextarea.h"
#include "../ObjectGraphics/graphicsgif.h"

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
    void begin();
private:
    bool* needEvolution;
    bool* needLearn;
    QString* nomAttak;
    PokemonInterface& you;
    PanelLearnAttaque* buttons;
    GraphicsTextArea* text;
    GraphicsGif* img;


    static constexpr double const&  HAUTEUR_TEXT_POURCENTAGE = .25;
    static constexpr double const&  LARGEUR_BUTTON_BOX = .25;
};

#endif // LEARNATTAQUESCENE_H
