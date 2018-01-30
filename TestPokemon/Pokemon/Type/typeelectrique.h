#ifndef TYPEELECTRIQUE_H
#define TYPEELECTRIQUE_H


#include "abstracttype.h"

class TypeElectrique : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeElectrique() throw ();

    //fonction
    static const TypeElectrique& getTypeElectrique();

    private:
    //constructeur
    TypeElectrique();                    //constructeur

};

#endif // TYPEELECTRIQUE_H
