#ifndef POKEMONINTERFACE_H
#define POKEMONINTERFACE_H

class PokemonInterface;

#include <QObject>
#include "../Type/abstracttype.h"
#include "../Statut/abstractstatut.h"
#include "../kernelobject.h"
#include "XpCourbe/abstractcourbe.h"
#include "../Exeption/outofrange_personalexeption.h"
#include "../Attaque/AttaqueEffect/abstractattaqueeffect.h"

class PokemonInterface : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
    virtual ~PokemonInterface() throw ()= 0;

    //fonction
    virtual int getPvAct()const       = 0;                                //donne les pvAct
    virtual int getBasePv()const      = 0;                               //donne la base des pv
    virtual int getBaseAttP()const    = 0;                             //donne la base de l'attaque physique
    virtual int getBaseAttS()const    = 0;                             //donne la base de l'attaque spéciale
    virtual int getBaseDefP()const    = 0;                             //donne la base de la defence physique
    virtual int getBaseDefS()const    = 0;                             //donne la base de la defence spéciale
    virtual int getBaseVitesse()const = 0;                          //donne la base de la vitesse

    virtual int getMaxPv()const   = 0;                                //donne le max des Pv;
    virtual int getAttP()const    = 0;                                 //donne l'attaque Physique
    virtual int getAttS()const    = 0;                                 //donne attaque Speciale
    virtual int getDefP()const    = 0;                                 //donne la defence physique
    virtual int getDefS()const    = 0;                                 //donne la defnece speciale
    virtual int getVitesse()const = 0;                              //donne la vitesse

    virtual QString getNom()const = 0;                              //donne le nom
    virtual unsigned int getLevel()const = 0;                                //donne le niveau
    virtual void infligerDegat(unsigned int v) = 0;                 //inflige des degats
    virtual double getAttCoef(const AbstractType& type)const = 0;        //donne le coef du attaque de type type sur la creature
    virtual bool isOneOfMyType(const AbstractType& type)const = 0;       //true si le poke poseeede ce type
    virtual void soigner(unsigned int v) = 0;                            //soigne le poke
    virtual QString getNomAttaque(unsigned int t)const throw(OutOfRange_PersonalExeption) = 0;   //donne le nom de la i-eme attaque (exeption out of range)
    virtual void    useAttaque(unsigned int t ,PokemonInterface& cible) throw(OutOfRange_PersonalExeption) = 0;  //utilise la i-eme attaque sur la cible
    virtual bool    isInLife()const = 0;                                    //permet de savoir si la creature est vivante
    virtual void    upgradeAttP(unsigned int nb = 1) = 0;                                      //augmente AttP
    virtual void    upgradeAttS(unsigned int nb = 1) = 0;                                      //augmente AttS
    virtual void    upgradeDefP(unsigned int nb = 1) = 0;                                      //augmente DefP
    virtual void    upgradeDefS(unsigned int nb = 1) = 0;                                      //augmente DefS
    virtual void    upgradeVit(unsigned int nb = 1) = 0;                                      //augmente Vit
    virtual void    decreaseAttP(unsigned int nb = 1) = 0;                                     //diminue Attp
    virtual void    decreaseDefS(unsigned int nb = 1) = 0;                                     //diminue defs
    virtual void    decreaseAttS(unsigned int nb = 1) = 0;                                     //diminue atts
    virtual void    decreaseDefP(unsigned int nb = 1) = 0;                                     //diminue defp
    virtual void    decreaseVit(unsigned int nb = 1) = 0;                                     //diminue vit

    virtual void    earnXp(const PokemonInterface& p) = 0;                   //gagne de xp
    virtual Xp getXp()const = 0;                                       //donne xp Act
    virtual void    soinComplet() = 0;                                      //soigne completement le pokemon
    virtual unsigned int getNbAttaque()const = 0;                           //donne le nd d'attaque de la creature
    virtual double  getPrecision()const = 0;                                //donne la precision
    virtual void    upgradePrecision(unsigned int nb = 1) = 0;                                 //augmente la precision
    virtual void    decreasePrecision(unsigned int nb = 1) = 0;                                //baisse la precision
    virtual void    setStatut(AbstractStatut* newStatut) = 0;                                                            //applique un statut
    virtual Xp     getBaseXp()const = 0;                                                           //donne xp de base

    virtual void   addAttaqueEffect(AttaqueEffect::AbstractAttaqueEffect* e) = 0;                                      //ajoute un effect d'attaque
    virtual void   finTour() = 0;                                 //applique tous les attaque effect et statut de fin de tour
    virtual bool   isUnderAttaqueEffect(const QString className) = 0;               //permet de savoir si le pokemon subit l'effect de cette class

    virtual double getEsquive()const = 0;                                           //donne le coef d'esquive du poke
    virtual void   upgradeEsquive(unsigned int nb = 1) = 0;                                            //augmente l'esquive
    virtual void   decreaseEsquive(unsigned int nb = 1) = 0;                                           //diminue l'esquive

    virtual bool   isLockAttaque()const = 0;                                    //permet de savoir si le poke est bloquer sur une attaque

    virtual bool   makeEvolution() = 0;                                         //fait evoluer le pokemon si il en est capable

signals:
    void veutApprendreAttaque(unsigned int * t);                                //emit quand il veut apprendre une attaque
    void veutEvoluer();                                                 //emit quand il veut evoluer

    void changedPv(const int pv);                                                     //emit quand les pv change
    void changedPvMax(const int PvMax);                                               //emit quand les pv Max change
    void changedLevel(const unsigned int lvl);                                        //emit quand le pokemon change de level
protected:
    PokemonInterface();
};

#endif // POKEMONINTERFACE_H
