#include "typePsy.h"

//--------------------------------------------------------------------------------------
//---------------------Constructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypePsy::TypePsy() : AbstractType("Psy",PSY)
{

}
//--------------------------------------------------------------------------------------
//----------------------Destructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypePsy::~TypePsy() throw (){

}
//--------------------------------------------------------------------------------------
//----------------------Fonction--------------------------------------------------------
//--------------------------------------------------------------------------------------
const TypePsy& TypePsy::getTypePsy(){
    static TypePsy t ;
    return t;
}