#include "Test/Type/alltesttype.h"


int main(int argc, char *argv[])
{

    Test_TypeAcier t_ta;
    QTest::qExec(&t_ta,argc,argv);
    Test_TypeCombat t_tc;
    QTest::qExec(&t_tc,argc,argv);
    Test_TypeDragon t_td;
    QTest::qExec(&t_td,argc,argv);
    Test_TypeEau t_te;
    QTest::qExec(&t_te,argc,argv);
    Test_TypeElectrique t_te2;
    QTest::qExec(&t_te2,argc,argv);


    return 0;
}
