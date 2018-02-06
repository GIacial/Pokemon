#include "test_typeeau.h"

#include <iostream>

using namespace std;
//-------------------------------------------------------------------------
Test_TypeEau::Test_TypeEau() : QObject(){

    this->type = new vector<AbstractType*>();
    this->coef = new vector<double>();
    this->typeTest = new TypeEau();

    this->type->push_back( new TypeAcier());
    this->coef->push_back(TableTypes::COEF_PEUEFFICACE);
    this->type->push_back( new TypeCombat());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeDragon());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeEau());
    this->coef->push_back(TableTypes::COEF_PEUEFFICACE);
    this->type->push_back( new TypeElectrique());
    this->coef->push_back(TableTypes::COEF_SUPEREFFICACE);
    this->type->push_back( new TypeFee());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeFeu());
    this->coef->push_back(TableTypes::COEF_PEUEFFICACE);
    this->type->push_back( new TypeGlace());
    this->coef->push_back(TableTypes::COEF_PEUEFFICACE);
    this->type->push_back( new TypeInsecte());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeNormal());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypePlante());
    this->coef->push_back(TableTypes::COEF_SUPEREFFICACE);
    this->type->push_back( new TypePoison());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypePsy());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeRoche());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeSol());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeSpectre());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeTenebres());
    this->coef->push_back(TableTypes::COEF_NORMAL);
    this->type->push_back( new TypeVol());
    this->coef->push_back(TableTypes::COEF_NORMAL);


}
//-------------------------------------------------------------------------
Test_TypeEau::~Test_TypeEau() throw(){
    delete typeTest;
    for( int i = this->type->size()-1 ; i >= 0  ; i--){
        delete type->at(i);
        type->pop_back();
    }
    delete coef;
    delete type;
}
//-------------------------------------------------------------------------
void Test_TypeEau::isWeakness(){
    for(unsigned int i = 0 ; i < this->coef->size() ; i++){
        if(this->coef->at(i) > TableTypes::COEF_NORMAL){
            QVERIFY(this->typeTest->isWeakness(*(this->type->at(i))));
        }
        else{

            QVERIFY(!this->typeTest->isWeakness(*(this->type->at(i))));
        }
    }
}
//-------------------------------------------------------------------------
void Test_TypeEau::isResistance(){
    for(unsigned int i = 0 ; i < this->coef->size() ; i++){
        if(this->coef->at(i) < TableTypes::COEF_NORMAL){
            QVERIFY(this->typeTest->isResistance(*(this->type->at(i))));
        }
        else{

            QVERIFY(!this->typeTest->isResistance(*(this->type->at(i))));
        }
    }
}
//-------------------------------------------------------------------------
void Test_TypeEau::getAttCoef(){
    for(unsigned int i = 0 ; i < this->coef->size() ; i++){
        QVERIFY(this->coef->at(i) == this->typeTest->getAttCoef(*(this->type->at(i))));
    }
}
//--------------------------------------------------------------------------
void Test_TypeEau::isOneOfMyType(){
    for(unsigned int i = 1 ; i < this->type->size() ; i++){
        if(this->typeTest->getNom() == this->type->at(i)->getNom()){
            QVERIFY(this->typeTest->isOneofMyType(*(this->type->at(i))));
        }
        else{
            QVERIFY(!this->typeTest->isOneofMyType(*(this->type->at(i))));
        }
    }
}
//--------------------------------------------------------------------------


