#ifndef PERSONALEXEPTION_H
#define PERSONALEXEPTION_H

#include <QString>

class PersonalExeption
{

public:
    //destructeur
    virtual ~PersonalExeption() throw();

    //fonction
    QString     getMsg()const;              //donne le msg de l'exeption

protected:
    //constructeur
    PersonalExeption(const QString m);
    PersonalExeption(const PersonalExeption& e);

    //operateur
    PersonalExeption& operator =(const PersonalExeption &e);

private:
    QString* msg;
};

#endif // PERSONALEXEPTION_H
