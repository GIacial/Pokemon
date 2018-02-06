#ifndef POKEMON_H
#define POKEMON_H
class AbstractPokemon;
#include <QObject>
#include "../Attaque/abstractattaque.h"
#include "../Statut/abstractstatut.h"
#include "../Type/abstracttype.h"

class AbstractPokemon : public QObject
{
    Q_OBJECT
public:
    static constexpr int const&  MAX_LEVEL = 100;
    static constexpr int const&  NB_MAX_ATTAQUE = 100;
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

    QString getNomAttaque(unsigned int t)const throw(QString);   //donne le nom de la i-eme attaque (exeption out of range)
    void    useAttaque(unsigned int t ,AbstractPokemon& cible) throw(QString);  //utilise la i-eme attaque sur la cible

signals:

public slots:

protected:
    //constructeur
    /**
     * @brief AbstractPokemon   constructeur d'une créature
     * @param nom               le nom de la créature
     * @param type              le type de la créature (sera détruit à la destruction de la créature)
     * @param basePv            la base de pv de la créature
     * @param baseAttP          la base d'attaque physique de la créature
     * @param baseDefP          la base de la defense de la créature
     * @param baseAttS          la base de l'attaque spéciale de la créature
     * @param baseDefS          la base de la defense speciale de la creature
     * @param baseVitesse       la base de la vitesse de la creature
     */
    explicit AbstractPokemon(const QString nom , AbstractType *type, int basePv , int baseAttP , int baseDefP , int baseAttS , int baseDefS , int baseVitesse);

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

};

#endif // POKEMON_H
