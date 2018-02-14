#ifndef BARVIE_H
#define BARVIE_H

#include <QObject>
#include "graphicsprogressbar.h"

class BarVie : public GraphicsProgressBar
{
    Q_OBJECT
public:
    explicit BarVie(unsigned int vieMax, QGraphicsItem *parent = 0);
    void recevoirDegat( int degat);                             //enleve degat  a la bar
    void recevoirSoin( int soin);                               //ajoute soin a la bar


    void    setMaximun(unsigned int max);
    void    setValue(unsigned int val);


signals:

public slots:

private:
    void choixCouleur();                                                //permet de mettre la couleur en fonction du remplissage
};

#endif // BARVIE_H