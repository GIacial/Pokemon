QT -= gui
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
    Attaque/Attaque/AlterationAttaque/rugissement.h \
    Attaque/Attaque/PhysicalAttaque/charge.h \
    Attaque/Attaque/alterationattque.h \
    Attaque/Attaque/physicalattaque.h \
    Attaque/Attaque/specialattaque.h \
    Attaque/abstractattaque.h \
    Interface/Graphics/ObjectGraphics/barvie.h \
    Interface/Graphics/ObjectGraphics/graphicsprogressbar.h \
    Interface/Graphics/graphicsview.h \
    Interface/Graphics/mainwindowspoke.h \
    Interface/combattestconsole.h \
    KernelMecanic/km_combat.h \
    Pokemon/Pokemon/fakemon.h \
    Pokemon/abstractpokemon.h \
    Pokemon/statalterator.h \
    Statut/abstractstatut.h \
    Type/abstracttype.h \
    Type/alltype.h \
    Type/doubletype.h \
    Type/tabletypes.h \
    Type/typeacier.h \
    Type/typecombat.h \
    Type/typedragon.h \
    Type/typeeau.h \
    Type/typeelectrique.h \
    Type/typefee.h \
    Type/typefeu.h \
    Type/typeglace.h \
    Type/typeinsecte.h \
    Type/typenormal.h \
    Type/typeplante.h \
    Type/typepoison.h \
    Type/typepsy.h \
    Type/typeroche.h \
    Type/typesol.h \
    Type/typespectre.h \
    Type/typetenebres.h \
    Type/typevol.h \
    kernelobject.h \
    Interface/Graphics/Scene/pokebatlescene.h \
    Pokemon/XpCourbe/abstractcourbe.h \
    Pokemon/XpCourbe/rapidecourbe.h \
    Exeption/personalexeption.h \
    Exeption/outofrange_personalexeption.h \
    Attaque/Attaque/PhysicalAttaque/fouetliane.h \
    Attaque/Attaque/PhysicalAttaque/griffe.h \
    Attaque/Attaque/SpecialAttaque/flammeche.h \
    Attaque/Attaque/SpecialAttaque/pistoletaeau.h \
    Pokemon/Pokemon/Gen1/bulbizarre.h \
    Pokemon/Pokemon/pokemonfactory.h \
    Pokemon/ListApprentissage/cellulelistapprentissage.h \
    Pokemon/ListApprentissage/listapprentissage.h \
    Exeption/metaconstructeurfail_personalexception.h

SOURCES += \
    Attaque/Attaque/AlterationAttaque/rugissement.cpp \
    Attaque/Attaque/PhysicalAttaque/charge.cpp \
    Attaque/Attaque/alterationattque.cpp \
    Attaque/Attaque/physicalattaque.cpp \
    Attaque/Attaque/specialattaque.cpp \
    Attaque/abstractattaque.cpp \
    Interface/Graphics/ObjectGraphics/barvie.cpp \
    Interface/Graphics/ObjectGraphics/graphicsprogressbar.cpp \
    Interface/Graphics/graphicsview.cpp \
    Interface/Graphics/mainwindowspoke.cpp \
    Interface/combattestconsole.cpp \
    KernelMecanic/km_combat.cpp \
    Pokemon/Pokemon/fakemon.cpp \
    Pokemon/abstractpokemon.cpp \
    Pokemon/statalterator.cpp \
    Statut/abstractstatut.cpp \
    Type/abstracttype.cpp \
    Type/doubletype.cpp \
    Type/tabletypes.cpp \
    Type/typeacier.cpp \
    Type/typecombat.cpp \
    Type/typedragon.cpp \
    Type/typeeau.cpp \
    Type/typeelectrique.cpp \
    Type/typefee.cpp \
    Type/typefeu.cpp \
    Type/typeglace.cpp \
    Type/typeinsecte.cpp \
    Type/typenormal.cpp \
    Type/typeplante.cpp \
    Type/typepoison.cpp \
    Type/typepsy.cpp \
    Type/typeroche.cpp \
    Type/typesol.cpp \
    Type/typespectre.cpp \
    Type/typetenebres.cpp \
    Type/typevol.cpp \
    kernelobject.cpp \
    main.cpp \
    Interface/Graphics/Scene/pokebatlescene.cpp \
    Pokemon/XpCourbe/abstractcourbe.cpp \
    Pokemon/XpCourbe/rapidecourbe.cpp \
    Exeption/personalexeption.cpp \
    Exeption/outofrange_personalexeption.cpp \
    Attaque/Attaque/PhysicalAttaque/fouetliane.cpp \
    Attaque/Attaque/PhysicalAttaque/griffe.cpp \
    Attaque/Attaque/SpecialAttaque/flammeche.cpp \
    Attaque/Attaque/SpecialAttaque/pistoletaeau.cpp \
    Pokemon/Pokemon/Gen1/bulbizarre.cpp \
    Pokemon/Pokemon/pokemonfactory.cpp \
    Pokemon/ListApprentissage/cellulelistapprentissage.cpp \
    Pokemon/ListApprentissage/listapprentissage.cpp \
    Exeption/metaconstructeurfail_personalexception.cpp
