#ifndef TYPEFEU_H
#define TYPEFEU_H


#include "abstracttype.h"

class TypeFeu : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeFeu() throw ();

    //fonction
    static const TypeFeu& getTypeFeu();

    private:
    //constructeur
    TypeFeu();                    //constructeur

};

#endif // TYPEFEU_H
