#ifndef POKEMON_H
#define POKEMON_H
class AbstractPokemon;
#include <QObject>
#include "../Attaque/abstractattaque.h"
#include "../Statut/abstractstatut.h"
#include "../Type/abstracttype.h"

class AbstractPokemon : public QObject
{
    Q_OBJECT
public:
    //destructeur
    virtual ~AbstractPokemon() throw () = 0;

signals:

public slots:

protected:
    //constructeur
    explicit AbstractPokemon(const QString nom , AbstractType *type, int basePv , int baseAttP , int baseDefP , int baseAttS , int baseDefS , int baseVitesse);

private:
    QString* nom;
    int* pvAct;
    int* basePv;
    int* baseAttP;
    int* baseDefP;
    int* baseAttS;
    int* baseDefS;
    int* baseVitesse;
    int* level;
    std::vector<AbstractAttaque>* attaque;
    AbstractStatut* statut;
    int* xpAct;
    AbstractType* type;

};

#endif // POKEMON_H
