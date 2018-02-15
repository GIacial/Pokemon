#include "metaconstructeurfail_personalexception.h"

MetaConstructeurFail_PersonalException::MetaConstructeurFail_PersonalException(const QString msg) :PersonalExeption(msg)
{

}

MetaConstructeurFail_PersonalException::MetaConstructeurFail_PersonalException(const MetaConstructeurFail_PersonalException &e)
    : PersonalExeption(e){

}

MetaConstructeurFail_PersonalException::~MetaConstructeurFail_PersonalException(){

}

MetaConstructeurFail_PersonalException& MetaConstructeurFail_PersonalException::operator = (const MetaConstructeurFail_PersonalException& e){
    PersonalExeption::operator =(e);
    return *this;
}
