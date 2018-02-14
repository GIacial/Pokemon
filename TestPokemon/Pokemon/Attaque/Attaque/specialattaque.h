#ifndef SPECIALATTAQUE_H
#define SPECIALATTAQUE_H

#include <QObject>
#include "../abstractattaque.h"

namespace Attaque{

class SpecialAttaque : public AbstractAttaque
{
    Q_OBJECT
public:
     virtual ~SpecialAttaque() throw();

signals:

public slots:
protected:
    //constructeur
     SpecialAttaque(AbstractPokemon &user, int precision, int puissance, AbstractType *type, const QString nom);
     //fonction surcharge
     int getAttaque(AbstractPokemon& cible)const;
     void attaqueEffect(AbstractPokemon& cible);

};

}

#endif // SPECIALATTAQUE_H
