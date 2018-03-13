#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include "./Pokemon/Pokemon/pokemonfactory.h"
#include "./Pokemon/capturedpokemon.h"

//console

#include "Interface/combattestconsole.h"

//graphics
#include <QApplication>
#include "Interface/Graphics/mainwindowspoke.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //app Graphics
    MainWindowsPoke w;
    cout << "Creation fentre principal" << endl;

    cout << "affichage" << endl;
    w.show();
    try{
        srand(time(NULL));
        /*
        //debut console app
        int departLV = 5;
        cout << "Niveau de depart ?" << endl;
        cin >> departLV;
        unsigned int num = 0;
        cout << "Choisie le numero de ton pokemon : entre 1 et "<< PokemonFactory::getInstance().getNbPoke()-1 << endl;
        do{
            cin >> num;
        }while (num>= PokemonFactory::getInstance().getNbPoke());

        CapturedPokemon* you = new CapturedPokemon(PokemonFactory::getInstance().createPoke(num,departLV));
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
*/


    }
    catch(PersonalExeption& e){
        cout << e.getMsg().toStdString() << endl;
    }


   return a.exec();

}
