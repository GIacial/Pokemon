#include "Test/Type/test_typeacier.h"


int main(int argc, char *argv[])
{

    Test_TypeAcier t_ta;
    QTest::qExec(&t_ta,argc,argv);
    return 0;
}
