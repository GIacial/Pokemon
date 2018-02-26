#ifndef TEST_TYPEINSECTE_H
#define TEST_TYPEINSECTE_H

#include <QObject>
#include <QtTest/QtTest>
#include "Pokemon/Type/alltype.h"

class Test_TypeInsecte : public QObject
{
    Q_OBJECT
public:
    Test_TypeInsecte();
    ~Test_TypeInsecte() throw ();
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

#endif // TEST_TYPEINSECTE_H
