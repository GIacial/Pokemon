#ifndef TYPEINSECTE_H
#define TYPEINSECTE_H


#include "abstracttype.h"

class TypeInsecte : public AbstractType
{
    Q_OBJECT

    public:
    //destructeur
    virtual ~TypeInsecte() throw ();

    //fonction
    static const TypeInsecte& getTypeInsecte();

    private:
    //constructeur
    TypeInsecte();                    //constructeur

};

#endif // TYPEINSECTE_H
