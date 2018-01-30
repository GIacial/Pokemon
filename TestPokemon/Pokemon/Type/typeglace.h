#ifndef TYPEGLACE_H
#define TYPEGLACE_H


#include "abstracttype.h"

class TypeGlace : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeGlace() throw ();

    //fonction
    static const TypeGlace& getTypeGlace();

    private:
    //constructeur
    TypeGlace();                    //constructeur

};

#endif // TYPEGLACE_H
