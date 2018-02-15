#include "listapprentissage.h"
#include <algorithm>
#include <QStack>
#include <iostream>

//------------------------------------------------------------------
//-----------------------constructeur+------------------------------
//------------------------------------------------------------------
ListApprentissage::ListApprentissage( std::vector<CelluleListApprentissage>  &app) : QObject()
{
    this->list = new QStack<CelluleListApprentissage*>();
    std::sort(app.begin(),app.end());

    for( int i= app.size()-1 ; i >= 0 ; i--){
        this->list->append(new CelluleListApprentissage( app[i]));
    }
}
//------------------------------------------------------------------
//------------------------Destructeur+------------------------------
//------------------------------------------------------------------
ListApprentissage::~ListApprentissage() throw (){
    while(!this->list->isEmpty()){
        delete list->pop();
    }
    delete list;
}
//------------------------------------------------------------------
//------------------------fonction---+------------------------------
//------------------------------------------------------------------
bool ListApprentissage::isMyLvl(unsigned int lv)const{
    bool t = false;
    if(!this->list->isEmpty()){
       t = this->list->top()->isMyLevel(lv);
    }
    return t;
}
//------------------------------------------------------------------
Attaque::AbstractAttaque* ListApprentissage::getNewAttaque(AbstractPokemon& user)throw (MetaConstructeurFail_PersonalException){
    Attaque::AbstractAttaque* n = NULL;
    if(!this->list->isEmpty()){
       n = this->list->top()->createInstanceAttaque(user);
       if(n == NULL){
           std::cerr << "Un probleme lors de la creation de l'attaque" << std::endl;
       }
       delete this->list->pop();
    }
    return n;
}
