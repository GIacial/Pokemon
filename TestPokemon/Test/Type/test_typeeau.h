#ifndef TEST_TYPEEAU_H
#define TEST_TYPEEAU_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeEau : public QObject
{
    Q_OBJECT
public:
     Test_TypeEau();
     ~Test_TypeEau() throw();

signals:

public slots:

private slots:
    void isWeakness();
    void isResistance();
    void getAttCoef();
    void isOneOfMyType();

private:
    std::vector<AbstractType *>* type;
    std::vector<double>* coef;
    AbstractType* typeTest;
};

#endif // TEST_TYPEEAU_H
