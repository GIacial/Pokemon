#ifndef TYPENORMAL_H
#define TYPENORMAL_H


#include "abstracttype.h"

class TypeNormal : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeNormal() throw ();

    //fonction
    static const TypeNormal& getTypeNormal();

    private:
    //constructeur
    TypeNormal();                    //constructeur

};

#endif // TYPENORMAL_H
