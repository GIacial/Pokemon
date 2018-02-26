#ifndef POKEMON_H
#define POKEMON_H
class AbstractPokemon;

#include <QObject>

#include "../Attaque/abstractattaque.h"
#include "statalterator.h"
#include "./ListApprentissage/listapprentissage.h"
#include "pokemoninterface.h"

class AbstractPokemon : public PokemonInterface
{
    Q_OBJECT
public:
    static constexpr int const&  MAX_LEVEL = 100;
    static constexpr int const&  NB_MAX_ATTAQUE = 4;
    static constexpr int const&  MIN_PV = 10;
    static constexpr int const&  MULTBASE = 2;
    static constexpr int const&  MINSTAT = 5;
    //destructeur
    virtual ~AbstractPokemon() throw () = 0;

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

    void    earnXp(const PokemonInterface& p);                   //gagne de xp
    Xp getXp()const;                                       //donne xp Act
    void    soinComplet();                                      //soigne completement le pokemon
    unsigned int getNbAttaque()const;                           //donne le nd d'attaque de la creature

    double  getPrecision()const;                                //donne la precision
    void    upgradePrecision(unsigned int nb = 1);                                 //augmente la precision
    void    decreasePrecision(unsigned int nb = 1);                                //baisse la precision

    void    setStatut(AbstractStatut* newStatut);                                                            //applique un statut
    Xp     getBaseXp()const;                                                           //donne xp de base

    void   addAttaqueEffect(AttaqueEffect::AbstractAttaqueEffect* e);                                      //ajoute un effect d'attaque
    void   appliqueAttaqueEffect();                                 //applique tous les attaque effect
    bool   isUnderAttaqueEffect(const QString className);               //permet de savoir si le pokemon subit l'effect de cette class

//fin des override

    //fonction
    virtual AbstractPokemon* evolution()const;                                       //produit un nouveau pokemon qui est l'evolution du pokemon (return null si pas d'evolution possible)

public slots:

protected:
    //constructeur
    explicit AbstractPokemon(const QString nom , AbstractType *type, int basePv , int baseAttP ,
                             int baseDefP , int baseAttS , int baseDefS , int baseVitesse ,
                             AbstractCourbe* xpCour, ListApprentissage* apprentissage,
                             unsigned int level = 1);
    explicit AbstractPokemon(const QString nom , AbstractType *type, int basePv , int baseAttP ,
                             int baseDefP , int baseAttS , int baseDefS , int baseVitesse ,
                             AbstractCourbe* xpCour, ListApprentissage* apprentissage,const AbstractPokemon& preEvolution,
                             unsigned int level = 1);//recup les attaque de la pre evolution
    //fonction
    void apprendreAttaque(Attaque::AbstractAttaque* a,unsigned int place = 0) throw (QString);                              //apprend une attaque (place => place pour l'attaque a enlever si plein
    virtual bool pretEvolution()const ;                                                                                  //permet de savoir si pret a l'evolution


private:
    //fonction
    bool statutEffect();                                                         //lance les effect de statut (bool dit si on peut attaquer)
    void levelUp();                                                              //fait les monter des niveau
    void apprendreAttaqueByLevelUp();                                            //apprend les attaque par level up
    void clearAttaqueEffect();                                                   //supprime tous les attaqueEffect

    //constructeur
    void generalConstructeur(const QString nom , AbstractType *type, int basePv , int baseAttP ,
                             int baseDefP , int baseAttS , int baseDefS , int baseVitesse ,
                             AbstractCourbe* xpCour, ListApprentissage* apprentissage,
                             unsigned int level);
    //variable
    QString* nom;
    int* pvAct;
    int* basePv;
    int* baseAttP;
    int* baseDefP;
    int* baseAttS;
    int* baseDefS;
    int* baseVitesse;
    unsigned int* level;
    std::vector<Attaque::AbstractAttaque*>* attaque;
    AbstractStatut* statut;
    Xp* xpAct;
    AbstractType* type;
    StatAlterator* alterations;
    AbstractCourbe* xpCourbe;
    ListApprentissage* nextAttaque;
    std::vector<AttaqueEffect::AbstractAttaqueEffect*>* effect;

};

#endif // POKEMON_H
