#ifndef TYPEFEU_H
#define TYPEFEU_H


#include "abstracttype.h"

class TypeFeu : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeFeu() throw ();

    //constructeur
    TypeFeu();                    //constructeur

};

#endif // TYPEFEU_H
