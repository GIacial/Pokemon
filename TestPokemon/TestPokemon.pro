QT -= gui
QT += testlib
QT       += core gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Pokemon/Attaque/Attaque/AlterationAttaque/brouillard.h \
    Pokemon/Attaque/Attaque/AlterationAttaque/grimace.h \
    Pokemon/Attaque/Attaque/AlterationAttaque/rugissement.h \
    Pokemon/Attaque/Attaque/AlterationAttaque/vampigraine.h \
    Pokemon/Attaque/Attaque/PhysicalAttaque/charge.h \
    Pokemon/Attaque/Attaque/PhysicalAttaque/fouetliane.h \
    Pokemon/Attaque/Attaque/PhysicalAttaque/griffe.h \
    Pokemon/Attaque/Attaque/SpecialAttaque/dracorage.h \
    Pokemon/Attaque/Attaque/SpecialAttaque/flammeche.h \
    Pokemon/Attaque/Attaque/SpecialAttaque/pistoletaeau.h \
    Pokemon/Attaque/Attaque/alterationattque.h \
    Pokemon/Attaque/Attaque/physicalattaque.h \
    Pokemon/Attaque/Attaque/specialattaque.h \
    Pokemon/Attaque/AttaqueEffect/AttaqueEffect/vampigraineeffect.h \
    Pokemon/Attaque/AttaqueEffect/abstractattaqueeffect.h \
    Pokemon/Attaque/abstractattaque.h \
    Pokemon/Exeption/metaconstructeurfail_personalexception.h \
    Pokemon/Exeption/outofrange_personalexeption.h \
    Pokemon/Exeption/personalexeption.h \
    Pokemon/Interface/AbstractInterface/abstractcombatinterface.h \
    Pokemon/Interface/Graphics/ObjectGraphics/barvie.h \
    Pokemon/Interface/Graphics/ObjectGraphics/graphicsprogressbar.h \
    Pokemon/Interface/Graphics/Scene/pokebatlescene.h \
    Pokemon/Interface/Graphics/graphicsview.h \
    Pokemon/Interface/Graphics/mainwindowspoke.h \
    Pokemon/Interface/combattestconsole.h \
    Pokemon/KernelMecanic/km_combat.h \
    Pokemon/Pokemon/ListApprentissage/cellulelistapprentissage.h \
    Pokemon/Pokemon/ListApprentissage/listapprentissage.h \
    Pokemon/Pokemon/Pokemon/Gen1/allgen1.h \
    Pokemon/Pokemon/Pokemon/Gen1/bulbizarre.h \
    Pokemon/Pokemon/Pokemon/Gen1/florizarre.h \
    Pokemon/Pokemon/Pokemon/Gen1/herbizarre.h \
    Pokemon/Pokemon/Pokemon/Gen1/salameche.h \
    Pokemon/Pokemon/Pokemon/fakemon.h \
    Pokemon/Pokemon/Pokemon/pokemonfactory.h \
    Pokemon/Pokemon/XpCourbe/abstractcourbe.h \
    Pokemon/Pokemon/XpCourbe/rapidecourbe.h \
    Pokemon/Pokemon/abstractpokemon.h \
    Pokemon/Pokemon/capturedpokemon.h \
    Pokemon/Pokemon/pokemoninterface.h \
    Pokemon/Pokemon/statalterator.h \
    Pokemon/Statut/abstractstatut.h \
    Pokemon/Statut/statut_brulure.h \
    Pokemon/Statut/statut_gel.h \
    Pokemon/Statut/statut_paralysie.h \
    Pokemon/Statut/statut_poison.h \
    Pokemon/Statut/statut_poison_grave.h \
    Pokemon/Statut/statut_sommeil.h \
    Pokemon/Type/abstracttype.h \
    Pokemon/Type/alltype.h \
    Pokemon/Type/doubletype.h \
    Pokemon/Type/tabletypes.h \
    Pokemon/Type/typeacier.h \
    Pokemon/Type/typecombat.h \
    Pokemon/Type/typedragon.h \
    Pokemon/Type/typeeau.h \
    Pokemon/Type/typeelectrique.h \
    Pokemon/Type/typefee.h \
    Pokemon/Type/typefeu.h \
    Pokemon/Type/typeglace.h \
    Pokemon/Type/typeinsecte.h \
    Pokemon/Type/typenormal.h \
    Pokemon/Type/typeplante.h \
    Pokemon/Type/typepoison.h \
    Pokemon/Type/typepsy.h \
    Pokemon/Type/typeroche.h \
    Pokemon/Type/typesol.h \
    Pokemon/Type/typespectre.h \
    Pokemon/Type/typetenebres.h \
    Pokemon/Type/typevol.h \
    Pokemon/kernelobject.h \
    Test/Type/alltesttype.h \
    Test/Type/test_typeacier.h \
    Test/Type/test_typecombat.h \
    Test/Type/test_typedragon.h \
    Test/Type/test_typeeau.h \
    Test/Type/test_typeelectrique.h

SOURCES += \
    Pokemon/Attaque/Attaque/AlterationAttaque/brouillard.cpp \
    Pokemon/Attaque/Attaque/AlterationAttaque/grimace.cpp \
    Pokemon/Attaque/Attaque/AlterationAttaque/rugissement.cpp \
    Pokemon/Attaque/Attaque/AlterationAttaque/vampigraine.cpp \
    Pokemon/Attaque/Attaque/PhysicalAttaque/charge.cpp \
    Pokemon/Attaque/Attaque/PhysicalAttaque/fouetliane.cpp \
    Pokemon/Attaque/Attaque/PhysicalAttaque/griffe.cpp \
    Pokemon/Attaque/Attaque/SpecialAttaque/dracorage.cpp \
    Pokemon/Attaque/Attaque/SpecialAttaque/flammeche.cpp \
    Pokemon/Attaque/Attaque/SpecialAttaque/pistoletaeau.cpp \
    Pokemon/Attaque/Attaque/alterationattque.cpp \
    Pokemon/Attaque/Attaque/physicalattaque.cpp \
    Pokemon/Attaque/Attaque/specialattaque.cpp \
    Pokemon/Attaque/AttaqueEffect/AttaqueEffect/vampigraineeffect.cpp \
    Pokemon/Attaque/AttaqueEffect/abstractattaqueeffect.cpp \
    Pokemon/Attaque/abstractattaque.cpp \
    Pokemon/Exeption/metaconstructeurfail_personalexception.cpp \
    Pokemon/Exeption/outofrange_personalexeption.cpp \
    Pokemon/Exeption/personalexeption.cpp \
    Pokemon/Interface/AbstractInterface/abstractcombatinterface.cpp \
    Pokemon/Interface/Graphics/ObjectGraphics/barvie.cpp \
    Pokemon/Interface/Graphics/ObjectGraphics/graphicsprogressbar.cpp \
    Pokemon/Interface/Graphics/Scene/pokebatlescene.cpp \
    Pokemon/Interface/Graphics/graphicsview.cpp \
    Pokemon/Interface/Graphics/mainwindowspoke.cpp \
    Pokemon/Interface/combattestconsole.cpp \
    Pokemon/KernelMecanic/km_combat.cpp \
    Pokemon/Pokemon/ListApprentissage/cellulelistapprentissage.cpp \
    Pokemon/Pokemon/ListApprentissage/listapprentissage.cpp \
    Pokemon/Pokemon/Pokemon/Gen1/bulbizarre.cpp \
    Pokemon/Pokemon/Pokemon/Gen1/florizarre.cpp \
    Pokemon/Pokemon/Pokemon/Gen1/herbizarre.cpp \
    Pokemon/Pokemon/Pokemon/Gen1/salameche.cpp \
    Pokemon/Pokemon/Pokemon/fakemon.cpp \
    Pokemon/Pokemon/Pokemon/pokemonfactory.cpp \
    Pokemon/Pokemon/XpCourbe/abstractcourbe.cpp \
    Pokemon/Pokemon/XpCourbe/rapidecourbe.cpp \
    Pokemon/Pokemon/abstractpokemon.cpp \
    Pokemon/Pokemon/capturedpokemon.cpp \
    Pokemon/Pokemon/pokemoninterface.cpp \
    Pokemon/Pokemon/statalterator.cpp \
    Pokemon/Statut/abstractstatut.cpp \
    Pokemon/Statut/statut_brulure.cpp \
    Pokemon/Statut/statut_gel.cpp \
    Pokemon/Statut/statut_paralysie.cpp \
    Pokemon/Statut/statut_poison.cpp \
    Pokemon/Statut/statut_poison_grave.cpp \
    Pokemon/Statut/statut_sommeil.cpp \
    Pokemon/Type/abstracttype.cpp \
    Pokemon/Type/doubletype.cpp \
    Pokemon/Type/tabletypes.cpp \
    Pokemon/Type/typeacier.cpp \
    Pokemon/Type/typecombat.cpp \
    Pokemon/Type/typedragon.cpp \
    Pokemon/Type/typeeau.cpp \
    Pokemon/Type/typeelectrique.cpp \
    Pokemon/Type/typefee.cpp \
    Pokemon/Type/typefeu.cpp \
    Pokemon/Type/typeglace.cpp \
    Pokemon/Type/typeinsecte.cpp \
    Pokemon/Type/typenormal.cpp \
    Pokemon/Type/typeplante.cpp \
    Pokemon/Type/typepoison.cpp \
    Pokemon/Type/typepsy.cpp \
    Pokemon/Type/typeroche.cpp \
    Pokemon/Type/typesol.cpp \
    Pokemon/Type/typespectre.cpp \
    Pokemon/Type/typetenebres.cpp \
    Pokemon/Type/typevol.cpp \
    Pokemon/kernelobject.cpp \
    Test/Type/test_typeacier.cpp \
    Test/Type/test_typecombat.cpp \
    Test/Type/test_typedragon.cpp \
    Test/Type/test_typeeau.cpp \
    Test/Type/test_typeelectrique.cpp \
    main.cpp
