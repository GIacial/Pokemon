#ifndef KM_COMBAT_H
#define KM_COMBAT_H

#include <QObject>
#include "../kernelobject.h"
#include "../Pokemon/pokemoninterface.h"

enum CibleKM_COMBAT{ME,OTHERS};

class KM_Combat : public KernelObject
{
    Q_OBJECT
public:
    explicit KM_Combat(PokemonInterface* you , PokemonInterface* other);
    virtual ~KM_Combat() throw ();

    void useAttaque(unsigned int t) throw(OutOfRange_PersonalExeption);                                    //lance la t-iem attaque de ton poke
    bool allInLife()const;                                                              //permet de savoir la fin d'un combat

    QString getNomCreature(CibleKM_COMBAT c)const;                                      //donne le nom de la creature cible
    int     getVieCreature(CibleKM_COMBAT c)const;                                      //donne la vie actuelle de la cible
    int     getMaxVieCreature(CibleKM_COMBAT c)const;                                   //donne la vie max de la cible
    QString getNomAttaqueCreature(CibleKM_COMBAT c,unsigned int t)const throw (OutOfRange_PersonalExeption);//donne le nom de l'attaque de la cible
    int     getLevelCreature(CibleKM_COMBAT c)const;                                    //donne le level de la cible
    bool    isInLife(CibleKM_COMBAT c)const;                                            //dit si la cible est en vie
    void    earnXp();                                                                   //fait gagner de xp a you
    unsigned int getNbAttaque()const;                                                   //donne le nombre d'attaque de you


signals:
    void PokemonVeutApprendreAttaque(unsigned int* t);                                                 //emit quand un pokem veut apprendre une attaque
    void PokemonVeutEvoluer(bool* t);                                                                  //emit quand you veut evoluer

public slots:
    void apprendreAttaqueSlot(unsigned int *t);                                                        //transmets le signal d'apprendtissage d'un poke
    void veutEvoluer(bool* t);                                                                         //transmets le signal d'evolution
protected:
    void playOneTurn(unsigned int t) throw(OutOfRange_PersonalExeption);                                   //fait un tour de combat

private:
    PokemonInterface* you;
    PokemonInterface* other;
};

#endif // KM_COMBAT_H
