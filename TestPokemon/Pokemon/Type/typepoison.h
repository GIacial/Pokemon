#ifndef TYPEPOISON_H
#define TYPEPOISON_H


#include "abstracttype.h"

class TypePoison : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypePoison() throw ();

    //fonction
    static const TypePoison& getTypePoison();

    private:
    //constructeur
    TypePoison();                    //constructeur

};

#endif // TYPEPOISON_H
