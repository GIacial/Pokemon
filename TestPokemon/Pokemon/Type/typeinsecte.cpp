#include "typeInsecte.h"

//--------------------------------------------------------------------------------------
//---------------------Constructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypeInsecte::TypeInsecte() : AbstractType("Insecte",INSECTE)
{

}
//--------------------------------------------------------------------------------------
//----------------------Destructeur-----------------------------------------------------
//--------------------------------------------------------------------------------------
TypeInsecte::~TypeInsecte() throw (){

}
//--------------------------------------------------------------------------------------
//----------------------Fonction--------------------------------------------------------
//--------------------------------------------------------------------------------------
const TypeInsecte& TypeInsecte::getTypeInsecte(){
    static TypeInsecte t ;
    return t;
}
