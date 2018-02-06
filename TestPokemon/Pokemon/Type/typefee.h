#ifndef TYPEFEE_H
#define TYPEFEE_H


#include "abstracttype.h"

class TypeFee : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeFee() throw ();

    //constructeur
    TypeFee();                    //constructeur

};

#endif // TYPEFEE_H
