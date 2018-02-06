#ifndef ABSTRACTATTAQUE_H
#define ABSTRACTATTAQUE_H

class AbstractAttaque;
#include <QObject>
#include "../Pokemon/abstractpokemon.h"
#include "../Pokemon/Type/abstracttype.h"

class AbstractAttaque : public QObject
{
    Q_OBJECT
public:
     virtual ~AbstractAttaque() throw() = 0;

    //fonction
     virtual void use(AbstractPokemon& cible) = 0;                  //utilise l'attaque
    unsigned int getPrecision()const;                               //donne la precision de l'attaque
    unsigned int getPuissance()const;                               //donne la puissance de l'attaque

    bool toucheLaCible()const;                                      //true si l'attaque doit toucher
    bool isSameTypeUser()const;                                     //donne si c'est le meme type que l'utilisateur
    QString getNom()const;                                          //donne le nom de l'attaque

    virtual int getAttaque(AbstractPokemon& cible)const;            //donne la puissance de l'attaque théorique de l'attaque

signals:

public slots:

protected:
    AbstractAttaque(AbstractPokemon& user, unsigned int precision , unsigned int puissance , AbstractType* type, const QString nom);

private:
    AbstractPokemon& utilisateur;
    unsigned int* precision;
    unsigned int* puissance;
    AbstractType* type;
    QString* nom;
};

#endif // ABSTRACTATTAQUE_H
