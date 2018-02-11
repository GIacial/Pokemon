#include "combattestconsole.h"

#include "Pokemon/Pokemon/fakemon.h"
#include "../KernelMecanic/km_combat.h"
#include <iostream>

using namespace std;

combatTestConsole::combatTestConsole() : QObject()
{

}

void combatTestConsole::launchCombat(){
    Fakemon y(5);
    Fakemon o(5);
    AbstractPokemon& you = y;
    AbstractPokemon& other = o;
    KM_Combat c(you,other);
    QObject::connect(&c,SIGNAL(sendMsg(QString)),this,SLOT(afficheTexte(QString)));
    while(c.allInLife()){
        cout << other.getNom().toStdString() <<" sauvage (Lv" << other.getLevel() << ") : " <<other.getPvAct() << "/" << other.getMaxPv() << endl;
        cout <<"ton "<< you.getNom().toStdString() <<" (Lv" << you.getLevel() << ") : " <<you.getPvAct() << "/" << you.getMaxPv() << endl;
        try{
            for(unsigned int i=0 ; i<AbstractPokemon::NB_MAX_ATTAQUE ; i++){
                cout << i <<":" <<you.getNomAttaque(i).toStdString() <<" ";
            }
        }
        catch(QString& r){
            cout << endl;
        }

        bool ok = false;
        unsigned int attaque;
        while(!ok){
            cout << "Choix de votre attaque" << endl;
            cin >> attaque;
            try{
                c.useAttaque(attaque);
                ok = true;
            }
            catch(QString& r){

            }
        }
        cout << endl << endl;

    }
    if(other.isInLife()){
        cout << "Vous etes mort :(" << endl;
    }
    else{
        cout << "Vous avez gagnez :)" << endl;
    }
}
//---------------------------------------------------------------------------------
void combatTestConsole::afficheTexte(QString m){
    cout << m.toStdString() << endl;
}
