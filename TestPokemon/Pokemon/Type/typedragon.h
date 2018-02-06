#ifndef TYPEDRAGON_H
#define TYPEDRAGON_H

#include "abstracttype.h"

class TypeDragon : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeDragon() throw ();

    //constructeur
    TypeDragon();                    //constructeur
};



#endif // TYPEDRAGON_H
