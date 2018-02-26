#ifndef ALLTESTTYPE_H
#define ALLTESTTYPE_H

#include "test_typeacier.h"
#include "test_typecombat.h"
#include "test_typedragon.h"
#include "test_typeeau.h"
#include "test_typeelectrique.h"
#include "test_typefee.h"
#include "test_typefeu.h"
#include "test_typeglace.h"
#include "test_typeinsecte.h"
#include "test_typenormal.h"

void launchTest_Type(int argc, char *argv[]){
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
    Test_TypeFee t_tf;
    QTest::qExec(&t_tf,argc,argv);
    Test_TypeFeu t_tf2;
    QTest::qExec(&t_tf2,argc,argv);
    Test_TypeGlace t_tg;
    QTest::qExec(&t_tg,argc,argv);
    Test_TypeInsecte t_ti;
    QTest::qExec(&t_ti,argc,argv);
    Test_TypeNormal t_tn;
    QTest::qExec(&t_tn,argc,argv);
}
#endif // ALLTESTTYPE_H
