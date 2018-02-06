#ifndef TYPECOMBAT_H
#define TYPECOMBAT_H

#include "abstracttype.h"

class TypeCombat : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeCombat() throw ();

    //constructeur
    TypeCombat();                    //constructeur

};

#endif // TYPECOMBAT_H
