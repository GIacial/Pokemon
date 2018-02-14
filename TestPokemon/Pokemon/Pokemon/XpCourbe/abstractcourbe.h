#ifndef ABSTRACTCOURBE_H
#define ABSTRACTCOURBE_H

#include <QObject>
#include "../../kernelobject.h"

class AbstractCourbe : public KernelObject
{
    Q_OBJECT
public:
    //destructeur
    virtual  ~AbstractCourbe() throw();

     //fonction
     bool isUpNextPalier(int const x);                  //vérifie si c'est au desus du palier xp du niveau suivant
     int  getBase()const;                               //donne la base de la courbe

    int getPredXp()const;          //donne xpPred

signals:

public slots:

protected:
     //constructeur
      AbstractCourbe(int base);
    //fonction
    virtual int calcXpNextLevel()const = 0;
      int getSuivXp()const;          //donne xpSuiv

private:
     //fonction
     //variable
     int* base;                     //xp de base du poke
     int* xpPred;                    //xp pour arriver à se niveau
     int* xpSuiv;                    //xp pour le prochain niveau
};

#endif // ABSTRACTCOURBE_H
