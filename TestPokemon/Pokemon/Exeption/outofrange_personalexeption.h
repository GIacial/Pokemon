#ifndef OUTOFRANGE_PERSONALEXEPTION_H
#define OUTOFRANGE_PERSONALEXEPTION_H

#include <QObject>
#include "personalexeption.h"

class OutOfRange_PersonalExeption : public PersonalExeption
{
public:
    explicit OutOfRange_PersonalExeption(const QString m);
    OutOfRange_PersonalExeption(const OutOfRange_PersonalExeption& e);
    //destructeur
    virtual ~OutOfRange_PersonalExeption() throw ();

    //operateur
    OutOfRange_PersonalExeption& operator = (const OutOfRange_PersonalExeption& e);


};

#endif // OUTOFRANGE_PERSONALEXEPTION_H
