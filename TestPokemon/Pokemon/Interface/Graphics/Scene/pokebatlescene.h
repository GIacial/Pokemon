#ifndef POKEBATLESCENE_H
#define POKEBATLESCENE_H

class PokeBatleScene;
#include <QObject>
#include <QGraphicsScene>


#include "../ObjectGraphics/batledisplaypokemon.h"
#include "../ObjectGraphics/graphicstextarea.h"
#include "./pokebatlescenekernel.h"
#include "../ObjectGraphics/attaquepanel.h"
#include "../ObjectGraphics/graphicsgif.h"

class PokeBatleScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PokeBatleScene(PokemonInterface *y , PokemonInterface *o,QObject *parent = nullptr);
    ~PokeBatleScene() throw();

    friend class PokeBatleSceneKernel;

signals:
    void endBattle();

public slots:
    void endTurn();


private:
    BatleDisplayPokemon* youDisplay;
    BatleDisplayPokemon* otherDisplay;
    GraphicsTextArea* textDisplay;
    PokeBatleSceneKernel* kernel;
    AttaquePanel* attaque;
    GraphicsGif* otherImg;
    GraphicsGif* youImg;
    bool* fin;


    static constexpr double const&  HAUTEUR_TEXT_POURCENTAGE = .25;

    void afficheTexte(QString m) ;
    void apprendreAttaque(unsigned int* t) ;                //veut apprendre une attaque
    void evoluer() ;                                        //veut evoluer

};

#endif // POKEBATLESCENE_H
