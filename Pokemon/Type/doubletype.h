#ifndef DOUBLETYPE_H
#define DOUBLETYPE_H

#include "abstracttype.h"

class DoubleType : public AbstractType
{
    Q_OBJECT
public:
    //constructeur
     DoubleType(TypeCreature f , TypeCreature s,const QString nom);
     DoubleType(const AbstractType& f , const AbstractType& s);

    //destructeur
    virtual ~DoubleType() throw();

    //fonction overrride
    virtual bool isWeakness(const AbstractType& type)const;                                         //permet de savoir si le type est une faiblesse
    virtual bool isResistance(const AbstractType& type)const;                                       //permet de savoir si le type est résisté
    virtual double getAttCoef(const AbstractType& att)const;              //permet de savoir le coef de degat de att sur def

private:
    //data
    TypeCreature* secondType;


};

#endif // DOUBLETYPE_H
