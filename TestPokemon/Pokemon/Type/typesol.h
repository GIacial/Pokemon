#ifndef TYPESOL_H
#define TYPESOL_H

#include "abstracttype.h"

class TypeSol : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeSol() throw ();

    //fonction
    static const TypeSol& getTypeSol();

    private:
    //constructeur
    TypeSol();                    //constructeur

};

#endif // TYPESOL_H
