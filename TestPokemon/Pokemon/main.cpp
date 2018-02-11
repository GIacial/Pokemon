#include <QCoreApplication>
#include <iostream>
#include "Interface/combattestconsole.h"
#include "time.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    combatTestConsole t;
    t.launchCombat();
    return 0;
}
