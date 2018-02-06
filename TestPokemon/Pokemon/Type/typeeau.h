#ifndef TYPEEAU_H
#define TYPEEAU_H


#include "abstracttype.h"

class TypeEau : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeEau() throw ();


    //constructeur
    TypeEau();                    //constructeur

};

#endif // TYPEEAU_H
