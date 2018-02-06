#ifndef TYPETENEBRES_H
#define TYPETENEBRES_H


#include "abstracttype.h"

class TypeTenebres : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeTenebres() throw ();

    //constructeur
    TypeTenebres();                    //constructeur

};

#endif // TYPETENEBRES_H
