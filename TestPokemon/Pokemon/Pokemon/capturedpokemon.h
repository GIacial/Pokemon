#ifndef CAPTUREDPOKEMON_H
#define CAPTUREDPOKEMON_H

#include <QObject>
#include "pokemoninterface.h"
#include "abstractpokemon.h"

class CapturedPokemon : public PokemonInterface
{
    Q_OBJECT
public:
    explicit CapturedPokemon(AbstractPokemon* p);                   //attention p va etre delete par l'object
    virtual ~CapturedPokemon() throw();
    //debut override

        //fonction
        int getPvAct()const;                                //donne les pvAct
        int getBasePv()const;                               //donne la base des pv
        int getBaseAttP()const;                             //donne la base de l'attaque physique
        int getBaseAttS()const;                             //donne la base de l'attaque spéciale
        int getBaseDefP()const;                             //donne la base de la defence physique
        int getBaseDefS()const;                             //donne la base de la defence spéciale
        int getBaseVitesse()const;                          //donne la base de la vitesse

        int getMaxPv()const;                                //donne le max des Pv;
        int getAttP()const;                                 //donne l'attaque Physique
        int getAttS()const;                                 //donne attaque Speciale
        int getDefP()const;                                 //donne la defence physique
        int getDefS()const;                                 //donne la defnece speciale
        int getVitesse()const;                              //donne la vitesse

        QString getNom()const;                              //donne le nom
        unsigned int getLevel()const;                                //donne le niveau

        void infligerDegat(unsigned int v);                 //inflige des degats
        double getAttCoef(const AbstractType& type)const;        //donne le coef du attaque de type type sur la creature
        bool isOneOfMyType(const AbstractType& type)const;       //true si le poke poseeede ce type
        void soigner(unsigned int v);                            //soigne le poke

        QString getNomAttaque(unsigned int t)const throw(OutOfRange_PersonalExeption);   //donne le nom de la i-eme attaque (exeption out of range)
        void    useAttaque(unsigned int t ,PokemonInterface& cible) throw(OutOfRange_PersonalExeption);  //utilise la i-eme attaque sur la cible

        bool    isInLife()const;                                    //permet de savoir si la creature est vivante

        void    upgradeAttP(unsigned int nb = 1);                                      //augmente AttP
        void    upgradeAttS(unsigned int nb = 1);                                      //augmente AttS
        void    upgradeDefP(unsigned int nb = 1);                                      //augmente DefP
        void    upgradeDefS(unsigned int nb = 1);                                      //augmente DefS
        void    upgradeVit(unsigned int nb = 1);                                      //augmente Vit

        void    decreaseAttP(unsigned int nb = 1);                                     //diminue Attp
        void    decreaseDefS(unsigned int nb = 1);                                     //diminue defs
        void    decreaseAttS(unsigned int nb = 1);                                     //diminue atts
        void    decreaseDefP(unsigned int nb = 1);                                     //diminue defp
        void    decreaseVit(unsigned int nb = 1);                                     //diminue vit

        void    upgradePrecision(unsigned int nb = 1);                                 //augmente la precision
        void    decreasePrecision(unsigned int nb = 1);                                //baisse la precision

        void    earnXp(const PokemonInterface& p);                   //gagne de xp
        Xp getXp()const;                                       //donne xp Act
        void    soinComplet();                                      //soigne completement le pokemon
        unsigned int getNbAttaque()const;                           //donne le nd d'attaque de la creature

        double  getPrecision()const;                                //donne la precision

        void    setStatut(AbstractStatut* newStatut);                                                            //applique un statut
        Xp     getBaseXp()const;                                                           //donne xp de base

        void   addAttaqueEffect(AttaqueEffect::AbstractAttaqueEffect* e);                                      //ajoute un effect d'attaque
        void   finTour() ;                                 //applique tous les attaque effect et statut de fin de tour
        bool   isUnderAttaqueEffect(const QString className);               //permet de savoir si le pokemon subit l'effect de cette class

        double getEsquive()const ;                                           //donne le coef d'esquive du poke
        void   upgradeEsquive(unsigned int nb = 1) ;                                            //augmente l'esquive
        void   decreaseEsquive(unsigned int nb = 1);                                           //diminue l'esquive

        bool   isLockAttaque()const;                                    //permet de savoir si le poke est bloquer sur une attaque


    //fin des override
signals:

public slots:
    void slot_apprendreAttaque(unsigned int* t);                                //attrape et relance le signal apprendre attaque
    void slot_evolution(bool*);                                                 //attrape et relance le signal evolution

    void slot_changedPv(const int pv);                                                //attrape et relance le signal changedPv
    void slot_changedPvMax(const int pvMax);                                          //attrape et relance le signal changedPvMax
    void slot_changedLvl(const uint lvl);                                              //attrape et relance changedLvl
private:
    void connectAllSignaux();                                                               //connect tous les signaux de poke
    AbstractPokemon* poke;
};

#endif // CAPTUREDPOKEMON_H
