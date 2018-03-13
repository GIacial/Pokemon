#ifndef GRAPHICSPROGRESSBAR_H
#define GRAPHICSPROGRESSBAR_H

#include <QGraphicsWidget>
#include <QPointer>

class GraphicsProgressBar : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit GraphicsProgressBar(QGraphicsItem *parent = 0);
    ~GraphicsProgressBar();

    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//style graphics de item

    virtual void    setMaximun(unsigned int max);
    virtual void    setValue(unsigned int val);
    int     getMaximun()const;
    int     getValue()const;
    QColor  getColor()const;

signals:

public slots:
    void refresh();                     //permet de mettre a jour l'object

protected:

    void    setColor(QColor color);
    qreal    calculFinBar()const;            //calcul la position de la fin de bar(entre 0 et 1)

private:
    unsigned int     montantActuel;              //montant actuel de la bar
    qreal   montantAnimation;           //permet de faire une modification fluide a chaque changement du montantActuel
    unsigned int     montantMax;                 //montant max de la bar
    QColor  couleurBar;                 //couleur de la bar
    QPointer<QTimer>  timerAnimationBar;         //chrono de l'animation de la bar

    //const
    static const int tempsAnimationBar=10; //temps entre chaque update de l'animation de la bar
    static constexpr qreal pasAnimationBar = 0.01;//pas de l'animation de la bar

    //fonction
    void    verifValInfMax();          //verifie si val <= max sinon val=max
    void    animationBar();            //lance la prochaine etape de l'animation de la bar
};

#endif // GRAPHICSPROGRESSBAR_H
