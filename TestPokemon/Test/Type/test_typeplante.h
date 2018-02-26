#ifndef TEST_TYPEPLANTE_H
#define TEST_TYPEPLANTE_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypePlante : public QObject
{
    Q_OBJECT
public:
     Test_TypePlante();
     ~Test_TypePlante() throw ();
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

#endif // TEST_TYPEPLANTE_H
