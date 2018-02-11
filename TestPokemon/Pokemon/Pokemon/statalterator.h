#ifndef STATALTERATOR_H
#define STATALTERATOR_H
class StatAlterator;
#include <QObject>
#include "../kernelobject.h"
#include "abstractpokemon.h"

class StatAlterator : public KernelObject
{
    Q_OBJECT
public:

    static constexpr int const&  MAX_UPGRADE = 6;
    static constexpr int const&  MAX_DECREASE = -6;
    //constructeur
    explicit StatAlterator(const AbstractPokemon& user);
    //destructeur
    virtual ~StatAlterator() throw();

    //fonction
    double getCoefAltAttP()const;                                   //donne le coef d'alt pour attP
    double getCoefAltAttS()const;                                   //donne le coef d'alt pour attS
    double getCoefAltDefP()const;                                   //donne le coef d'alt pour defP
    double getCoefAltDefS()const;                                   //donne le coef d'alt pour defS
    double getCoefAltVit()const;                                   //donne le coef d'alt pour vit

    void   upgradeAttP();                                           //augmente la stat
    void   upgradeAttS();                                           //augmente la stat
    void   upgradeDefP();                                           //augmente la stat
    void   upgradeDefS();                                           //augmente la stat
    void   upgradeVit();                                           //augmente la stat

    void   decreaseAttP();                                           //baisse la stat
    void   decreaseAttS();                                           //baisse la stat
    void   decreaseDefP();                                           //baisse la stat
    void   decreaseDefS();                                           //baisse la stat
    void   decreaseVit();                                           //baisse la stat


signals:

public slots:

protected:

private:

    double getAlteratorCoef(int t)const;                             //donne le coef d'alteration d'un stat
    void   genericUpgrade(int* val ,const QString textStat);          //augmente la valeur contenu dans val et emet un texte avec textStat
    void   genericDecrease(int *val, const QString textStat);         //diminue ...
    //stat
    int* altAttP;
    int* altAttS;
    int* altDefS;
    int* altDefP;
    int* altVit;
    const AbstractPokemon& user;
};

#endif // STATALTERATOR_H
