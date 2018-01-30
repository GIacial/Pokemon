#ifndef TYPESPECTRE_H
#define TYPESPECTRE_H


#include "abstracttype.h"

class TypeSpectre : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeSpectre() throw ();

    //fonction
    static const TypeSpectre& getTypeSpectre();

    private:
    //constructeur
    TypeSpectre();                    //constructeur

};

#endif // TYPESPECTRE_H
