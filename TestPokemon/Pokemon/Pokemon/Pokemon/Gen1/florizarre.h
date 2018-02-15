#ifndef FLORIZARRE_H
#define FLORIZARRE_H

#include <QObject>
#include "../../abstractpokemon.h"
#include "herbizarre.h"

class Florizarre : public AbstractPokemon
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Florizarre(unsigned int level = 1);
    explicit Florizarre(const Herbizarre& b);

    //destructeur
    virtual ~Florizarre() throw ();

signals:

public slots:
private:
    static ListApprentissage* getListApprentissage();
    //var static
    static constexpr int const&  BASE_PV = 80;
    static constexpr int const&  BASE_ATTP = 82;
    static constexpr int const&  BASE_DEFP = 83;
    static constexpr int const&  BASE_ATTS = 100;
    static constexpr int const&  BASE_DEFS = 100;
    static constexpr int const&  BASE_VIT = 80;

    static constexpr int const&  BASE_XP = 20;
};

#endif // FLORIZARRE_H
