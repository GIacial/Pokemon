#include "test_typeacier.h"
#include "Pokemon/Type/alltype.h"
#include <iostream>

using namespace std;
//-------------------------------------------------------------------------
void Test_TypeAcier::isWeakness(){
    const AbstractType& acier = TypeAcier::getTypeAcier();

    QVERIFY(!acier.isWeakness(TypeAcier::getTypeAcier()));
    QVERIFY(acier.isWeakness(TypeCombat::getTypeCombat()));
    QVERIFY(!acier.isWeakness(TypeDragon::getTypeDragon()));
    QVERIFY(!acier.isWeakness(TypeEau::getTypeEau()));
    QVERIFY(!acier.isWeakness(TypeElectrique::getTypeElectrique()));
    QVERIFY(acier.isWeakness(TypeFeu::getTypeFeu()));
    QVERIFY(!acier.isWeakness(TypeFee::getTypeFee()));
    QVERIFY(!acier.isWeakness(TypeGlace::getTypeGlace()));
    QVERIFY(!acier.isWeakness(TypeInsecte::getTypeInsecte()));
    QVERIFY(!acier.isWeakness(TypeNormal::getTypeNormal()));
    QVERIFY(!acier.isWeakness(TypePlante::getTypePlante()));
    QVERIFY(!acier.isWeakness(TypePoison::getTypePoison()));
    QVERIFY(!acier.isWeakness(TypePsy::getTypePsy()));
    QVERIFY(!acier.isWeakness(TypeRoche::getTypeRoche()));
    QVERIFY(acier.isWeakness(TypeSol::getTypeSol()));
    QVERIFY(!acier.isWeakness(TypeSpectre::getTypeSpectre()));
    QVERIFY(!acier.isWeakness(TypeTenebres::getTypeTenebres()));
    QVERIFY(!acier.isWeakness(TypeVol::getTypeVol()));
}
//-------------------------------------------------------------------------
void Test_TypeAcier::isResistance(){
    const AbstractType& acier = TypeAcier::getTypeAcier();

    QVERIFY(acier.isResistance(TypeAcier::getTypeAcier()));
    QVERIFY(!acier.isResistance(TypeCombat::getTypeCombat()));
    QVERIFY(acier.isResistance(TypeDragon::getTypeDragon()));
    QVERIFY(!acier.isResistance(TypeEau::getTypeEau()));
    QVERIFY(!acier.isResistance(TypeElectrique::getTypeElectrique()));
    QVERIFY(!acier.isResistance(TypeFeu::getTypeFeu()));
    QVERIFY(acier.isResistance(TypeFee::getTypeFee()));
    QVERIFY(acier.isResistance(TypeGlace::getTypeGlace()));
    QVERIFY(acier.isResistance(TypeInsecte::getTypeInsecte()));
    QVERIFY(acier.isResistance(TypeNormal::getTypeNormal()));
    QVERIFY(acier.isResistance(TypePlante::getTypePlante()));
    QVERIFY(acier.isResistance(TypePoison::getTypePoison()));
    QVERIFY(acier.isResistance(TypePsy::getTypePsy()));
    QVERIFY(acier.isResistance(TypeRoche::getTypeRoche()));
    QVERIFY(!acier.isResistance(TypeSol::getTypeSol()));
    QVERIFY(!acier.isResistance(TypeSpectre::getTypeSpectre()));
    QVERIFY(!acier.isResistance(TypeTenebres::getTypeTenebres()));
    QVERIFY(acier.isResistance(TypeVol::getTypeVol()));
}
