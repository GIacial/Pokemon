#ifndef TEST_TYPEGLACE_H
#define TEST_TYPEGLACE_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeGlace : public QObject
{
    Q_OBJECT
public:
     Test_TypeGlace();
     ~Test_TypeGlace() throw ();
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

#endif // TEST_TYPEGLACE_H
