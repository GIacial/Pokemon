#ifndef TYPEROCHE_H
#define TYPEROCHE_H


#include "abstracttype.h"

class TypeRoche : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeRoche() throw ();

    //constructeur
    TypeRoche();                    //constructeur

};
#endif // TYPEROCHE_H
