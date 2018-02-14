#ifndef CELLULELISTAPPRENTISSAGE_H
#define CELLULELISTAPPRENTISSAGE_H

class CelluleListApprentissage;

#include <QObject>
#include "../../Attaque/abstractattaque.h"

class CelluleListApprentissage
{
public:
    //constructeur
    CelluleListApprentissage(const CelluleListApprentissage& c);
    explicit CelluleListApprentissage(unsigned int lv , QMetaObject attaque);
    //destructeur
    virtual ~CelluleListApprentissage() throw ();
    //operateur
    CelluleListApprentissage& operator = (const CelluleListApprentissage& c);
    bool operator <(const CelluleListApprentissage& c)const;                                         //comparaison par lv
    //fonction

    Attaque::AbstractAttaque* createInstanceAttaque(AbstractPokemon &user)const;                     //cree une instance de l'attaque
    bool    isMyLevel(unsigned int lv)const;                                                         //verifie si mon lv correspond au lv de l'attaque

signals:

public slots:

private:
    unsigned int* lvl;
    QMetaObject attaque;
};

#endif // CELLULELISTAPPRENTISSAGE_H
