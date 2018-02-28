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
    double getCoefAltPrec()const;                                   //donne la stat de precision
    double getCoefAltEsquive()const;                                //donne la stat d'esquive

    void   upgradeAttP(unsigned int nb = 1);                                           //augmente la stat
    void   upgradeAttS(unsigned int nb = 1);                                           //augmente la stat
    void   upgradeDefP(unsigned int nb = 1);                                           //augmente la stat
    void   upgradeDefS(unsigned int nb = 1);                                           //augmente la stat
    void   upgradeVit(unsigned int nb = 1);                                           //augmente la stat
    void   upgradePrec(unsigned int nb = 1);                                           //augmente la precision
    void   upgradeEsquive(unsigned int nb = 1);                                        //augmente l'esquive

    void   decreaseAttP(unsigned int nb = 1);                                           //baisse la stat
    void   decreaseAttS(unsigned int nb = 1);                                           //baisse la stat
    void   decreaseDefP(unsigned int nb = 1);                                           //baisse la stat
    void   decreaseDefS(unsigned int nb = 1);                                           //baisse la stat
    void   decreaseVit(unsigned int nb = 1);                                           //baisse la stat
    void   decreasePrec(unsigned int nb = 1);                                          //baisse la precision
    void   decreaseEsquive(unsigned int nb = 1);                                       //baisse l'esquive

    void   resetAlt();                                                                 //remets tout a la base


signals:

public slots:

protected:

private:

    double getAlteratorCoef(int t)const;                             //donne le coef d'alteration d'un stat
    void   genericUpgrade(int* val ,const QString textStat,unsigned int nb);          //augmente la valeur contenu dans val et emet un texte avec textStat
    void   genericDecrease(int *val, const QString textStat,unsigned int nb);         //diminue ...
    //stat
    int* altAttP;
    int* altAttS;
    int* altDefS;
    int* altDefP;
    int* altVit;
    int* precision;
    int* esquive;
    const AbstractPokemon& user;
};

#endif // STATALTERATOR_H
