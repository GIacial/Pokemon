#ifndef MAINWINDOWSPOKE_H
#define MAINWINDOWSPOKE_H

#include <QMainWindow>
#include "graphicsview.h"
#include "../../Pokemon/pokemoninterface.h"

class MainWindowsPoke : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowsPoke(PokemonInterface* y,QWidget *parent = nullptr);
    //destructeur
    virtual ~MainWindowsPoke() throw();

signals:

public slots:

    void createBattleScene();                           //cree la scene de combat
    void createEvolutionScene();                        //cree la scene d'evolution
    void createLearnAttaqueScene(QString nomAttaque,bool needEvolution);
private:
    GraphicsView* view;
    PokemonInterface* you;
    PokemonInterface* other;

};

#endif // MAINWINDOWSPOKE_H
