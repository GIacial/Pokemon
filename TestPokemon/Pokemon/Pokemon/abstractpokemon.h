#ifndef POKEMON_H
#define POKEMON_H
class AbstractPokemon;
#include <QObject>
#include "../Attaque/abstractattaque.h"
#include "../Statut/abstractstatut.h"
#include "../Type/abstracttype.h"
#include "../kernelobject.h"
#include "statalterator.h"
#include "XpCourbe/abstractcourbe.h"
#include "../Exeption/outofrange_personalexeption.h"

class AbstractPokemon : public KernelObject
{
    Q_OBJECT
public:
    static constexpr int const&  MAX_LEVEL = 100;
    static constexpr int const&  NB_MAX_ATTAQUE = 100;
    static constexpr int const&  MIN_PV = 10;
    static constexpr int const&  MULTBASE = 2;
    static constexpr int const&  MINSTAT = 5;
    //destructeur
    virtual ~AbstractPokemon() throw () = 0;

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
    int getLevel()const;                                //donne le niveau

    void infligerDegat(unsigned int v);                 //inflige des degats
    double getAttCoef(const AbstractType& type)const;        //donne le coef du attaque de type type sur la creature
    bool isOneOfMyType(const AbstractType& type)const;       //true si le poke poseeede ce type
    void soigner(unsigned int v);                            //soigne le poke

    QString getNomAttaque(unsigned int t)const throw(OutOfRange_PersonalExeption);   //donne le nom de la i-eme attaque (exeption out of range)
    void    useAttaque(unsigned int t ,AbstractPokemon& cible) throw(OutOfRange_PersonalExeption);  //utilise la i-eme attaque sur la cible

    bool    isInLife()const;                                    //permet de savoir si la creature est vivante

    void    upgradeAttP();                                      //augmente AttP
    void    upgradeAttS();                                      //augmente AttS
    void    upgradeDefP();                                      //augmente DefP
    void    upgradeDefS();                                      //augmente DefS
    void    upgradeVit();                                      //augmente Vit

    void    decreaseAttP();                                     //diminue Attp
    void    decreaseDefS();                                     //diminue defs
    void    decreaseAttS();                                     //diminue atts
    void    decreaseDefP();                                     //diminue defp
    void    decreaseVit();                                     //diminue vit

    void    earnXp(const AbstractPokemon& p);                   //gagne de xp
    int     getXp()const;                                       //donne xp Act
    void    soinComplet();                                      //soigne completement le pokemon
    unsigned int getNbAttaque()const;                           //donne le nd d'attaque de la creature


signals:

public slots:

protected:
    //constructeur
    explicit AbstractPokemon(const QString nom , AbstractType *type, int basePv , int baseAttP ,
                             int baseDefP , int baseAttS , int baseDefS , int baseVitesse , AbstractCourbe* xpCour,
                             int level = 1);

    //fonction
    void apprendreAttaque(AbstractAttaque* a,unsigned int place = 0) throw (QString);                              //apprend une attaque (place => place pour l'attaque a enlever si plein
private:
    QString* nom;
    int* pvAct;
    int* basePv;
    int* baseAttP;
    int* baseDefP;
    int* baseAttS;
    int* baseDefS;
    int* baseVitesse;
    int* level;
    std::vector<AbstractAttaque*>* attaque;
    AbstractStatut* statut;
    int* xpAct;
    AbstractType* type;
    StatAlterator* alterations;
    AbstractCourbe* xpCourbe;

};

#endif // POKEMON_H
