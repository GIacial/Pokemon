#ifndef TEST_TYPEFEE_H
#define TEST_TYPEFEE_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"


class Test_TypeFee : public QObject
{
    Q_OBJECT
public:
    Test_TypeFee();
    ~Test_TypeFee() throw ();

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

#endif // TEST_TYPEFEE_H
