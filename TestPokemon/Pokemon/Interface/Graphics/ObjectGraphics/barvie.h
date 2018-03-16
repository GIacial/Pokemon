#ifndef BARVIE_H
#define BARVIE_H

#include <QObject>
#include "graphicsprogressbar.h"

class BarVie : public GraphicsProgressBar
{
    Q_OBJECT
public:
    explicit BarVie(unsigned int vieMax, QGraphicsItem *parent = 0);

signals:

public slots:
    void    setMaximun( int max);
    void    setValue( int val);

private:
    void choixCouleur();                                                //permet de mettre la couleur en fonction du remplissage
};

#endif // BARVIE_H
