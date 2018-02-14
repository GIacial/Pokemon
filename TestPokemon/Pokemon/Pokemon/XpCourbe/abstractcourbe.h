#ifndef ABSTRACTCOURBE_H
#define ABSTRACTCOURBE_H

#include <QObject>
#include "../../kernelobject.h"

typedef unsigned long int Xp;

class AbstractCourbe : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
    virtual  ~AbstractCourbe() throw();

     //fonction
     bool isUpNextPalier(const Xp x);                  //vérifie si c'est au desus du palier xp du niveau suivant
     Xp  getBase()const;                               //donne la base de la courbe

     Xp getPredXp()const;          //donne xpPred

signals:

public slots:

protected:
     //constructeur
      AbstractCourbe(Xp base);
    //fonction
    virtual Xp calcXpNextLevel()const = 0;
      Xp getSuivXp()const;          //donne xpSuiv

private:
     //fonction
     //variable
     Xp* base;                     //xp de base du poke
     Xp* xpPred;                    //xp pour arriver à se niveau
     Xp* xpSuiv;                    //xp pour le prochain niveau
};

#endif // ABSTRACTCOURBE_H
