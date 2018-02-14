#include "outofrange_personalexeption.h"

OutOfRange_PersonalExeption::OutOfRange_PersonalExeption(const QString m) : PersonalExeption(m)
{

}

OutOfRange_PersonalExeption::OutOfRange_PersonalExeption(const OutOfRange_PersonalExeption &e) : PersonalExeption(e)
{


}

OutOfRange_PersonalExeption::~OutOfRange_PersonalExeption() throw(){

}

OutOfRange_PersonalExeption& OutOfRange_PersonalExeption::operator = (const OutOfRange_PersonalExeption& e){
   PersonalExeption::operator =(e);
   return *this;
}
