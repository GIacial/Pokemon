#ifndef TYPEPOISON_H
#define TYPEPOISON_H


#include "abstracttype.h"

class TypePoison : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypePoison() throw ();

    //constructeur
    TypePoison();                    //constructeur

};

#endif // TYPEPOISON_H
