#ifndef METACONSTRUCTEURFAIL_PERSONALEXCEPTION_H
#define METACONSTRUCTEURFAIL_PERSONALEXCEPTION_H

#include "personalexeption.h"


class MetaConstructeurFail_PersonalException : public PersonalExeption
{
public:
    explicit MetaConstructeurFail_PersonalException(const QString msg);
    MetaConstructeurFail_PersonalException(const MetaConstructeurFail_PersonalException& e);
    virtual ~MetaConstructeurFail_PersonalException() throw ();
    MetaConstructeurFail_PersonalException& operator = (const MetaConstructeurFail_PersonalException& e);


};

#endif // METACONSTRUCTEURFAIL_PERSONALEXCEPTION_H
