#ifndef TYPEINSECTE_H
#define TYPEINSECTE_H


#include "abstracttype.h"

class TypeInsecte : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeInsecte() throw ();

    //constructeur
    TypeInsecte();                    //constructeur

};

#endif // TYPEINSECTE_H
