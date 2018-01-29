#ifndef TYPEACIER_H
#define TYPEACIER_H

#include "abstracttype.h"

class TypeAcier : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeAcier() throw ();

    //fonction
    static const TypeAcier& getTypeAcier();

    private:
    //constructeur
    TypeAcier();                    //constructeur
};

#endif // TYPEACIER_H
