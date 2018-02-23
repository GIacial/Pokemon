#ifndef LISTAPPRENTISSAGE_H
#define LISTAPPRENTISSAGE_H
class ListApprentissage;
#include <QObject>
#include "cellulelistapprentissage.h"

class ListApprentissage : public QObject
{
    Q_OBJECT
public:
     ListApprentissage(std::vector<CelluleListApprentissage> &app);
     virtual ~ListApprentissage() throw();

    //fonction
     bool isMyLvl(unsigned int lv)const;                   //permet de savoir si la prochainne attaque est a mon lvl
     Attaque::AbstractAttaque* getNewAttaque(PokemonInterface& user)throw (MetaConstructeurFail_PersonalException);        //donne une instance de la nouvelle attaque

signals:

public slots:

private:
     QStack<CelluleListApprentissage*>* list;
};

#endif // LISTAPPRENTISSAGE_H
