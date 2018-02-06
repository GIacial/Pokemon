#ifndef TYPENORMAL_H
#define TYPENORMAL_H


#include "abstracttype.h"

class TypeNormal : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeNormal() throw ();

    //constructeur
    TypeNormal();                    //constructeur

};

#endif // TYPENORMAL_H
