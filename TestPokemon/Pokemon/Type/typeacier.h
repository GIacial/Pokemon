#ifndef TYPEACIER_H
#define TYPEACIER_H

#include "abstracttype.h"

class TypeAcier : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeAcier() throw ();

    //constructeur
    TypeAcier();                    //constructeur
};

#endif // TYPEACIER_H
