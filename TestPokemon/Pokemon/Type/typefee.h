#ifndef TYPEFEE_H
#define TYPEFEE_H


#include "abstracttype.h"

class TypeFee : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeFee() throw ();

    //fonction
    static const TypeFee& getTypeFee();

    private:
    //constructeur
    TypeFee();                    //constructeur

};

#endif // TYPEFEE_H
