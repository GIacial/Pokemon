#ifndef SALAMECHE_H
#define SALAMECHE_H

#include <QObject>
#include "../../abstractpokemon.h"

class Salameche : public AbstractPokemon
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Salameche(unsigned int level = 1);
    virtual ~Salameche() throw ();

signals:

public slots:

private:
    static ListApprentissage* getListApprentissage();
    //var static
    static constexpr int const&  BASE_PV = 39;
    static constexpr int const&  BASE_ATTP = 52;
    static constexpr int const&  BASE_DEFP = 43;
    static constexpr int const&  BASE_ATTS = 60;
    static constexpr int const&  BASE_DEFS = 50;
    static constexpr int const&  BASE_VIT = 65;

    static constexpr int const&  BASE_XP = 10;
};

#endif // SALAMECHE_H
