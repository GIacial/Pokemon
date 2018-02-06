#ifndef TEST_TYPEELECTRIQUE_H
#define TEST_TYPEELECTRIQUE_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeElectrique : public QObject
{
    Q_OBJECT
public:
     Test_TypeElectrique();
     ~Test_TypeElectrique() throw();

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

#endif // TEST_TYPEELECTRIQUE_H
