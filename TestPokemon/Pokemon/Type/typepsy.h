#ifndef TYPEPSY_H
#define TYPEPSY_H


#include "abstracttype.h"

class TypePsy : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypePsy() throw ();

    //fonction
    static const TypePsy& getTypePsy();

    private:
    //constructeur
    TypePsy();                    //constructeur

};

#endif // TYPEPSY_H
