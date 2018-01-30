#include "typePlante.h"

//--------------------------------------------------------------------------------------
//---------------------Constructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypePlante::TypePlante() : AbstractType("Plante",PLANTE)
{

}
//--------------------------------------------------------------------------------------
//----------------------Destructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypePlante::~TypePlante() throw (){

}
//--------------------------------------------------------------------------------------
//----------------------Fonction--------------------------------------------------------
//--------------------------------------------------------------------------------------
const TypePlante& TypePlante::getTypePlante(){
    static TypePlante t ;
    return t;
}
