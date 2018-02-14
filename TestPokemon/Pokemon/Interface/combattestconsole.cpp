#include "combattestconsole.h"

#include <iostream>

using namespace std;
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
combatTestConsole::combatTestConsole(AbstractPokemon* y , AbstractPokemon* o) : QObject()
{

    this->c = new KM_Combat(y,o);
    QObject::connect(c,SIGNAL(sendMsg(QString)),this,SLOT(afficheTexte(QString)));
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
combatTestConsole::~combatTestConsole() throw (){
    delete c;
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void combatTestConsole::launchCombat(){
    while(c->allInLife()){
        cout << c->getNomCreature(CibleKM_COMBAT::OTHERS).toStdString()
             <<" sauvage (Lv" << c->getLevelCreature(CibleKM_COMBAT::OTHERS) << ") : "
            <<c->getVieCreature(CibleKM_COMBAT::OTHERS) << "/"
           << c->getMaxVieCreature(CibleKM_COMBAT::OTHERS) << endl;

        cout <<"ton "<< c->getNomCreature(CibleKM_COMBAT::ME).toStdString()
            <<" (Lv" << c->getLevelCreature(CibleKM_COMBAT::ME)
           << ") : "<<c->getVieCreature(CibleKM_COMBAT::ME) << "/"
          << c->getMaxVieCreature(CibleKM_COMBAT::ME)<< endl;
        try{
            for(unsigned int i=0 ; i<AbstractPokemon::NB_MAX_ATTAQUE ; i++){
                cout << i <<":" <<c->getNomAttaqueCreature(CibleKM_COMBAT::ME,i).toStdString() <<" ";
            }
        }
        catch(OutOfRange_PersonalExeption& ){

        }
        cout << endl;

        bool ok = false;
        unsigned int attaque;
        while(!ok){
            cout << "Choix de votre attaque" << endl;
            cin >> attaque;
            try{
                c->useAttaque(attaque);
                ok = true;
            }
            catch(OutOfRange_PersonalExeption& r){
                cerr << "OutofRange :"+r.getMsg().toStdString() << endl;
            }
        }
        cout << endl << endl;

    }
    if(c->isInLife(CibleKM_COMBAT::OTHERS)){
        cout << "Vous etes mort :(" << endl;
    }
    else{
        cout << "Vous avez gagnez :)" << endl;
        c->earnXp();
    }
}
//---------------------------------------------------------------------------------
void combatTestConsole::afficheTexte(QString m){
    cout << m.toStdString() << endl;
}
