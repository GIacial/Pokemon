#ifndef BULBIZARRE_H
#define BULBIZARRE_H

#include <QObject>
#include "../../abstractpokemon.h"

class Bulbizarre : public AbstractPokemon
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Bulbizarre(unsigned int level=1);
    virtual ~Bulbizarre() throw ();

signals:

public slots:
private:
    static ListApprentissage* getListApprentissage();
    //var static
    static constexpr int const&  BASE_PV = 45;
    static constexpr int const&  BASE_ATTP = 49;
    static constexpr int const&  BASE_DEFP = 49;
    static constexpr int const&  BASE_ATTS = 65;
    static constexpr int const&  BASE_DEFS = 65;
    static constexpr int const&  BASE_VIT = 45;

    static constexpr int const&  BASE_XP = 10;
};

#endif // BULBIZARRE_H
