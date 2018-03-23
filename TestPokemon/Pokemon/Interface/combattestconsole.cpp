#include "combattestconsole.h"

#include <iostream>

using namespace std;
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
combatTestConsole::combatTestConsole(PokemonInterface *y , PokemonInterface *o) : AbstractCombatInterface(y,o)
{


}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
combatTestConsole::~combatTestConsole() throw (){

}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void combatTestConsole::launchCombat(){
    while(this->getSystemCombat().allInLife()){
        cout << this->getSystemCombat().getNomCreature(CibleKM_COMBAT::OTHERS).toStdString()
             <<" sauvage (Lv" << this->getSystemCombat().getLevelCreature(CibleKM_COMBAT::OTHERS) << ") : "
            <<this->getSystemCombat().getVieCreature(CibleKM_COMBAT::OTHERS) << "/"
           << this->getSystemCombat().getMaxVieCreature(CibleKM_COMBAT::OTHERS) << endl;

        cout <<"ton "<< this->getSystemCombat().getNomCreature(CibleKM_COMBAT::ME).toStdString()
            <<" (Lv" << this->getSystemCombat().getLevelCreature(CibleKM_COMBAT::ME)
           << ") : "<<this->getSystemCombat().getVieCreature(CibleKM_COMBAT::ME) << "/"
          << this->getSystemCombat().getMaxVieCreature(CibleKM_COMBAT::ME)<< endl;
        try{
            for(unsigned int i=0 ; i<this->getSystemCombat().getNbAttaque() ; i++){
                cout << i <<":" <<this->getSystemCombat().getNomAttaqueCreature(CibleKM_COMBAT::ME,i).toStdString() <<" ";
            }
        }
        catch(OutOfRange_PersonalExeption& r){
            cerr << "OutofRange :"+r.getMsg().toStdString() << endl;
        }
        cout << endl;

        bool ok = false;
        unsigned int attaque = 0;
        while(!ok){
            if(!this->getSystemCombat().getLockAttaqueCreature(CibleKM_COMBAT::ME)){
                do{
                cout << "Choix de votre attaque" << endl;
                cin >> attaque;
                }while(attaque > this->getSystemCombat().getNbAttaque());
            }

            try{
                this->useAttaque(attaque);
                ok = true;
            }
            catch(OutOfRange_PersonalExeption& r){
                cerr << "OutofRange :"+r.getMsg().toStdString() << endl;
            }
        }
        cout << endl << endl;

    }
    if(this->getSystemCombat().isInLife(CibleKM_COMBAT::OTHERS)){
        cout << "Vous etes mort :(" << endl;
    }
    else{
        cout << "Vous avez gagnez :)" << endl;
        this->win();
    }
}
//---------------------------------------------------------------------------------
void combatTestConsole::afficheTexte(QString m){
    cout << m.toStdString() << endl;
}
//---------------------------------------------------------------------------------
void combatTestConsole::apprendreAttaque(QString t){
    uint n ;
    cout << this->getYou().getNom().toStdString() << " veut apprendre " << t.toStdString() << endl;
    cout << "Quel attaque a oublie ?" << endl;
    try{
        for(unsigned int i=0 ; i<this->getSystemCombat().getNbAttaque() ; i++){
            cout << i <<":" <<this->getSystemCombat().getNomAttaqueCreature(CibleKM_COMBAT::ME,i).toStdString() <<" ";
        }
    }
    catch(OutOfRange_PersonalExeption& r){
        cerr << "OutofRange :"+r.getMsg().toStdString() << endl;
    }
    cout << endl;
    cin >> n;
    //mettre le code d'apprentissage
    this->getYou().apprendreAttaque(n);
}
//---------------------------------------------------------------------------------
void combatTestConsole::evoluer(){
    bool ok = false;
    cout << this->getSystemCombat().getNomCreature(CibleKM_COMBAT::ME).toStdString() << " veut evoluer" << endl;
    cout << "Le laisser faire ? 1:ok" << endl;
    int a = 0;
    cin >> a;
    ok = (a == 1);
    //code de l'evolution
    if(ok){
        this->getYou().makeEvolution();
    }
}
