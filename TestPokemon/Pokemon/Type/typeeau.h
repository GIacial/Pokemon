#ifndef TYPEEAU_H
#define TYPEEAU_H


#include "abstracttype.h"

class TypeEau : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeEau() throw ();

    //fonction
    static const TypeEau& getTypeEau();

    private:
    //constructeur
    TypeEau();                    //constructeur

};

#endif // TYPEEAU_H
