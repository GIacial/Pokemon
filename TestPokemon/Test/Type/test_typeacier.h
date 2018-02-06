#ifndef TEST_TYPEACIER_H
#define TEST_TYPEACIER_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"


class Test_TypeAcier : public QObject
{
    Q_OBJECT
public:
    //constructeur
    Test_TypeAcier();
    //destructeur
    ~Test_TypeAcier() throw();
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

#endif // TEST_TYPEACIER_H
