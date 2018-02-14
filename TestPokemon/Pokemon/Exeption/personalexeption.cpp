#include "personalexeption.h"

PersonalExeption::PersonalExeption(const QString m)
{
    this->msg = new QString(m);
}

PersonalExeption::PersonalExeption(const PersonalExeption &e){
    this->msg = new QString(e.getMsg());
}

PersonalExeption::~PersonalExeption() throw(){
    delete msg;
}

PersonalExeption& PersonalExeption::operator =(const PersonalExeption& e){
    if(this != &e){
        (*msg) = e.getMsg();
    }
    return * this;
}

QString PersonalExeption::getMsg()const{
    return* msg;
}
