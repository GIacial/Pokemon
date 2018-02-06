#ifndef TEST_TYPEDRAGON_H
#define TEST_TYPEDRAGON_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeDragon : public QObject
{
    Q_OBJECT
public:
     Test_TypeDragon();
     ~Test_TypeDragon() throw();

signals:

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

#endif // TEST_TYPEDRAGON_H
