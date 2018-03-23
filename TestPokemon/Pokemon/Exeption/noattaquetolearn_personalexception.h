#ifndef NOATTAQUETOLEARN_PERSONALEXCEPTION_H
#define NOATTAQUETOLEARN_PERSONALEXCEPTION_H

#include "./personalexeption.h"

class NoAttaqueToLearn_PersonalException : public PersonalExeption
{
public:
    NoAttaqueToLearn_PersonalException(const QString msg);
    NoAttaqueToLearn_PersonalException(NoAttaqueToLearn_PersonalException& e);
    virtual ~NoAttaqueToLearn_PersonalException() throw ();
    NoAttaqueToLearn_PersonalException& operator=(NoAttaqueToLearn_PersonalException& e);
};

#endif // NOATTAQUETOLEARN_PERSONALEXCEPTION_H
