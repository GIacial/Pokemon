#ifndef HERBIZARRE_H
#define HERBIZARRE_H

#include <QObject>
#include "../../abstractpokemon.h"
#include "bulbizarre.h"

class Herbizarre : public AbstractPokemon
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Herbizarre(unsigned int level = 1);
    explicit Herbizarre(const Bulbizarre& b);
    //destructeur
    virtual ~Herbizarre() throw();

    //override
     AbstractPokemon* evolution()const;                                       //produit un nouveau pokemon qui est l'evolution du pokemon (return null si pas d'evolution possible)
     bool pretEvolution()const ;                                                                                  //permet de savoir si pret a l'evolution

signals:

public slots:

protected:
    //override

private:

    static ListApprentissage* getListApprentissage();
    //var static
    static constexpr int const&  BASE_PV = 60;
    static constexpr int const&  BASE_ATTP = 62;
    static constexpr int const&  BASE_DEFP = 63;
    static constexpr int const&  BASE_ATTS = 80;
    static constexpr int const&  BASE_DEFS = 80;
    static constexpr int const&  BASE_VIT = 60;

    static constexpr int const&  BASE_XP = 15;


    static constexpr unsigned int const&  EVO_LEVEL = 32;
};

#endif // HERBIZARRE_H
