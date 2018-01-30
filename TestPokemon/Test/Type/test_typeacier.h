#ifndef TEST_TYPEACIER_H
#define TEST_TYPEACIER_H

#include <QObject>
#include <QtTest/QtTest>

class Test_TypeAcier : public QObject
{
    Q_OBJECT
public:

signals:

private slots:
    void isWeakness();
    void isResistance();
};

#endif // TEST_TYPEACIER_H
