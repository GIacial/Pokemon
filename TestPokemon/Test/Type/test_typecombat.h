#ifndef TEST_TYPECOMBAT_H
#define TEST_TYPECOMBAT_H

#include <QObject>
#include <QtTest/QtTest>
#include"Pokemon/Type/alltype.h"

class Test_TypeCombat : public QObject
{
    Q_OBJECT
public:
     Test_TypeCombat();
     ~Test_TypeCombat();

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

#endif // TEST_TYPECOMBAT_H
