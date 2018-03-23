#include "noattaquetolearn_personalexception.h"

NoAttaqueToLearn_PersonalException::NoAttaqueToLearn_PersonalException(const QString msg) : PersonalExeption(msg)
{

}

NoAttaqueToLearn_PersonalException::NoAttaqueToLearn_PersonalException(NoAttaqueToLearn_PersonalException& e) : PersonalExeption(e)
{

}

NoAttaqueToLearn_PersonalException::~NoAttaqueToLearn_PersonalException() throw(){

}

NoAttaqueToLearn_PersonalException& NoAttaqueToLearn_PersonalException::operator =(NoAttaqueToLearn_PersonalException& e){
    if(this!= &e){
        PersonalExeption::operator =(e);
    }
    return * this;
}
