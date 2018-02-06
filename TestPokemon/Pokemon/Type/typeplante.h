#ifndef TYPEPLANTE_H
#define TYPEPLANTE_H


#include "abstracttype.h"

class TypePlante : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypePlante() throw ();

    //constructeur
    TypePlante();                    //constructeur

};

#endif // TYPEPLANTE_H
