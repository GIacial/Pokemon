#include <QCoreApplication>
#include <iostream>
#include <time.h>

//console

#include "Pokemon/Pokemon/fakemon.h"
#include "Interface/combattestconsole.h"

//graphics
#include <QApplication>
#include "Interface/Graphics/mainwindowspoke.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    Fakemon you (5);
    while(true){
        cout<< "Un nouveau combat" << endl;

        you.soinComplet();
        Fakemon o ((rand()%(you.getLevel()+1))+1);
        combatTestConsole t(you,o);
        t.launchCombat();

        cout  <<endl<<endl;
    }
    return 0;


    QApplication a(argc, argv);
    MainWindowsPoke w;
    w.show();

   return a.exec();

}
