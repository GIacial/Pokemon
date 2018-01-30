#ifndef TYPEVOL_H
#define TYPEVOL_H


#include "abstracttype.h"

class TypeVol : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeVol() throw ();

    //fonction
    static const TypeVol& getTypeVol();

    private:
    //constructeur
    TypeVol();                    //constructeur

};

#endif // TYPEVOL_H
