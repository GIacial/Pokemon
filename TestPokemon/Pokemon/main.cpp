#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include "./Pokemon/Pokemon/pokemonfactory.h"

//console

#include "Pokemon/Pokemon/fakemon.h"
#include "Pokemon/Pokemon/Gen1/bulbizarre.h"
#include "Interface/combattestconsole.h"

//graphics
#include <QApplication>
#include "Interface/Graphics/mainwindowspoke.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try{
        srand(time(NULL));
        unsigned int num = 0;
        cout << "Choisie le numero de ton pokemon : entre 0 et "<< PokemonFactory::getInstance().getNbPoke()-1 << endl;
        do{
            cin >> num;
        }while (num>= PokemonFactory::getInstance().getNbPoke());

        AbstractPokemon* you = PokemonFactory::getInstance().createPoke(num,5);
        while(true){
            cout<< "Un nouveau combat" << endl;

            you->soinComplet();
            unsigned int lv = (rand()%(you->getLevel()+1))+1;
            AbstractPokemon* other = NULL;

            other = PokemonFactory::getInstance().createRandomPokemon(lv);
            if(other == NULL){
                cerr << "Probleme Allocation ennemie " << endl;
                return 0;
            }
            combatTestConsole t(you,other);
            t.launchCombat();

            cout  <<endl<<endl;
            delete other;
        }
        delete you;



       /* MainWindowsPoke w;
        w.show();*/
    }
    catch(PersonalExeption& e){
        cout << e.getMsg().toStdString() << endl;
    }


   return a.exec();

}
