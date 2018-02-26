#ifndef TEST_TYPENORMAL_H
#define TEST_TYPENORMAL_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeNormal : public QObject
{
    Q_OBJECT
public:
    Test_TypeNormal();
    ~Test_TypeNormal() throw ();
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

#endif // TEST_TYPENORMAL_H
