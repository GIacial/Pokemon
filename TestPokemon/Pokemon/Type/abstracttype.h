#ifndef ABSTRACTTYPE_H
#define ABSTRACTTYPE_H

#include <QObject>
#include "tabletypes.h"

class DoubleType;
/**
 * @brief The AbstractType class    Definit de facon abstraite le type d'une créature
 */
class AbstractType : public QObject
{
    Q_OBJECT
public:

    //destructeur
    virtual ~AbstractType() throw() = 0;                                                    //destructeur


    //fonction
    virtual bool isWeakness(const AbstractType& type)const;                                         //permet de savoir si le type est une faiblesse
    virtual bool isResistance(const AbstractType& type)const;                                       //permet de savoir si le type est résisté
    virtual double getAttCoef(const AbstractType& att)const;                                        //permet de savoir le coef de degat de att sur def
    QString getNom()const;                                                                          //donne le nom du type
    virtual bool isOneofMyType(const AbstractType& att)const;                                       //verifie si le type att est l'un des type de this

    //friend
    friend class DoubleType;
signals:

public slots:


protected:
    //constructeur
     AbstractType(const QString nom,const TypeCreature t);                          //constructeur



    //fonction
    TypeCreature getType()const;

private:

    //data
    QString* nom;                                                                           //le nom du type
    TypeCreature* type;                                                                     //la valeur enum du type
};

#endif // ABSTRACTTYPE_H
