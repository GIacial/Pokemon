#include "typeFeu.h"

//--------------------------------------------------------------------------------------
//---------------------Constructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypeFeu::TypeFeu() : AbstractType("Feu",FEU)
{

}
//--------------------------------------------------------------------------------------
//----------------------Destructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypeFeu::~TypeFeu() throw (){

}
//--------------------------------------------------------------------------------------
//----------------------Fonction--------------------------------------------------------
//--------------------------------------------------------------------------------------
const TypeFeu& TypeFeu::getTypeFeu(){
    static TypeFeu t ;
    return t;
}
