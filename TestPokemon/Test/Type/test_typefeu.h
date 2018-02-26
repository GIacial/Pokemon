#ifndef TEST_TYPEFEU_H
#define TEST_TYPEFEU_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"


class Test_TypeFeu : public QObject
{
    Q_OBJECT
public:
     Test_TypeFeu();
     ~Test_TypeFeu() throw ();

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

#endif // TEST_TYPEFEU_H
