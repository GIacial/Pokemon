#ifndef ALTERATIONATTQUE_H
#define ALTERATIONATTQUE_H

#include <QObject>
#include "../abstractattaque.h"

class AlterationAttque : public AbstractAttaque
{
    Q_OBJECT
public:
    virtual ~AlterationAttque() throw();
signals:

public slots:
protected :

    //constructeur
    explicit AlterationAttque(AbstractPokemon &user, int precision, AbstractType *type, const QString nom);
    //fonction surcharge
    int getAttaque(AbstractPokemon& cible)const;
};

#endif // ALTERATIONATTQUE_H
