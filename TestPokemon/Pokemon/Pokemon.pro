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
    Attaque/Attaque/AlterationAttaque/brouillard.h \
    Attaque/Attaque/AlterationAttaque/rugissement.h \
    Attaque/Attaque/PhysicalAttaque/charge.h \
    Attaque/Attaque/PhysicalAttaque/fouetliane.h \
    Attaque/Attaque/PhysicalAttaque/griffe.h \
    Attaque/Attaque/SpecialAttaque/flammeche.h \
    Attaque/Attaque/SpecialAttaque/pistoletaeau.h \
    Attaque/Attaque/alterationattque.h \
    Attaque/Attaque/physicalattaque.h \
    Attaque/Attaque/specialattaque.h \
    Attaque/abstractattaque.h \
    Exeption/metaconstructeurfail_personalexception.h \
    Exeption/outofrange_personalexeption.h \
    Exeption/personalexeption.h \
    Interface/Graphics/ObjectGraphics/barvie.h \
    Interface/Graphics/ObjectGraphics/graphicsprogressbar.h \
    Interface/Graphics/Scene/pokebatlescene.h \
    Interface/Graphics/graphicsview.h \
    Interface/Graphics/mainwindowspoke.h \
    Interface/combattestconsole.h \
    KernelMecanic/km_combat.h \
    Pokemon/ListApprentissage/cellulelistapprentissage.h \
    Pokemon/ListApprentissage/listapprentissage.h \
    Pokemon/Pokemon/Gen1/allgen1.h \
    Pokemon/Pokemon/Gen1/bulbizarre.h \
    Pokemon/Pokemon/Gen1/florizarre.h \
    Pokemon/Pokemon/Gen1/herbizarre.h \
    Pokemon/Pokemon/Gen1/salameche.h \
    Pokemon/Pokemon/fakemon.h \
    Pokemon/Pokemon/pokemonfactory.h \
    Pokemon/XpCourbe/abstractcourbe.h \
    Pokemon/XpCourbe/rapidecourbe.h \
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
    Attaque/Attaque/SpecialAttaque/dracorage.h \
    Attaque/Attaque/AlterationAttaque/grimace.h \
    Statut/statut_brulure.h \
    Pokemon/pokemoninterface.h \
    Pokemon/capturedpokemon.h \
    Interface/AbstractInterface/abstractcombatinterface.h \
    Attaque/AttaqueEffect/abstractattaqueeffect.h \
    Attaque/Attaque/AlterationAttaque/vampigraine.h \
    Attaque/AttaqueEffect/AttaqueEffect/vampigraineeffect.h \
    Statut/statut_poison.h \
    Statut/statut_poison_grave.h \
    Statut/statut_paralysie.h \
    Statut/statut_gel.h \
    Statut/statut_sommeil.h \
    Attaque/Attaque/AlterationAttaque/poudretoxik.h \
    Attaque/Attaque/AlterationAttaque/poudredodo.h \
    Attaque/Attaque/PhysicalAttaque/belier.h \
    Attaque/Attaque/PhysicalAttaque/trancheherbe.h \
    Attaque/Attaque/AlterationAttaque/douxparfum.h \
    Attaque/Attaque/AlterationAttaque/croissance.h \
    Attaque/Attaque/PhysicalAttaque/damocles.h \
    Attaque/Attaque/AlterationAttaque/synthese.h \
    Attaque/Attaque/PhysicalAttaque/canongraine.h \
    Attaque/Attaque/SpecialAttaque/lancesoleil.h \
    Attaque/Attaque/PhysicalAttaque/tempeteflorale.h \
    Interface/Graphics/ObjectGraphics/batledisplaypokemon.h \
    Interface/Graphics/ObjectGraphics/graphicstextarea.h \
    Interface/Graphics/Scene/pokebatlescenekernel.h \
    Interface/Graphics/ObjectGraphics/attaquebutton.h \
    Interface/Graphics/ObjectGraphics/attaquepanel.h \
    Interface/Graphics/ObjectGraphics/graphicsgif.h \
    Interface/Graphics/Scene/evolutionscene.h \
    Interface/Graphics/Scene/learnattaquescene.h \
    Exeption/noattaquetolearn_personalexception.h \
    Interface/Graphics/ObjectGraphics/learnattaquebutton.h \
    Interface/Graphics/ObjectGraphics/panellearnattaque.h

SOURCES += \
    Attaque/Attaque/AlterationAttaque/brouillard.cpp \
    Attaque/Attaque/AlterationAttaque/rugissement.cpp \
    Attaque/Attaque/PhysicalAttaque/charge.cpp \
    Attaque/Attaque/PhysicalAttaque/fouetliane.cpp \
    Attaque/Attaque/PhysicalAttaque/griffe.cpp \
    Attaque/Attaque/SpecialAttaque/flammeche.cpp \
    Attaque/Attaque/SpecialAttaque/pistoletaeau.cpp \
    Attaque/Attaque/alterationattque.cpp \
    Attaque/Attaque/physicalattaque.cpp \
    Attaque/Attaque/specialattaque.cpp \
    Attaque/abstractattaque.cpp \
    Exeption/metaconstructeurfail_personalexception.cpp \
    Exeption/outofrange_personalexeption.cpp \
    Exeption/personalexeption.cpp \
    Interface/Graphics/ObjectGraphics/barvie.cpp \
    Interface/Graphics/ObjectGraphics/graphicsprogressbar.cpp \
    Interface/Graphics/Scene/pokebatlescene.cpp \
    Interface/Graphics/graphicsview.cpp \
    Interface/Graphics/mainwindowspoke.cpp \
    Interface/combattestconsole.cpp \
    KernelMecanic/km_combat.cpp \
    Pokemon/ListApprentissage/cellulelistapprentissage.cpp \
    Pokemon/ListApprentissage/listapprentissage.cpp \
    Pokemon/Pokemon/Gen1/bulbizarre.cpp \
    Pokemon/Pokemon/Gen1/florizarre.cpp \
    Pokemon/Pokemon/Gen1/herbizarre.cpp \
    Pokemon/Pokemon/Gen1/salameche.cpp \
    Pokemon/Pokemon/fakemon.cpp \
    Pokemon/Pokemon/pokemonfactory.cpp \
    Pokemon/XpCourbe/abstractcourbe.cpp \
    Pokemon/XpCourbe/rapidecourbe.cpp \
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
    Attaque/Attaque/SpecialAttaque/dracorage.cpp \
    Attaque/Attaque/AlterationAttaque/grimace.cpp \
    Statut/statut_brulure.cpp \
    Pokemon/pokemoninterface.cpp \
    Pokemon/capturedpokemon.cpp \
    Interface/AbstractInterface/abstractcombatinterface.cpp \
    Attaque/AttaqueEffect/abstractattaqueeffect.cpp \
    Attaque/Attaque/AlterationAttaque/vampigraine.cpp \
    Attaque/AttaqueEffect/AttaqueEffect/vampigraineeffect.cpp \
    Statut/statut_poison.cpp \
    Statut/statut_poison_grave.cpp \
    Statut/statut_paralysie.cpp \
    Statut/statut_gel.cpp \
    Statut/statut_sommeil.cpp \
    Attaque/Attaque/AlterationAttaque/poudretoxik.cpp \
    Attaque/Attaque/AlterationAttaque/poudredodo.cpp \
    Attaque/Attaque/PhysicalAttaque/belier.cpp \
    Attaque/Attaque/PhysicalAttaque/trancheherbe.cpp \
    Attaque/Attaque/AlterationAttaque/douxparfum.cpp \
    Attaque/Attaque/AlterationAttaque/croissance.cpp \
    Attaque/Attaque/PhysicalAttaque/damocles.cpp \
    Attaque/Attaque/AlterationAttaque/synthese.cpp \
    Attaque/Attaque/PhysicalAttaque/canongraine.cpp \
    Attaque/Attaque/SpecialAttaque/lancesoleil.cpp \
    Attaque/Attaque/PhysicalAttaque/tempeteflorale.cpp \
    Interface/Graphics/ObjectGraphics/batledisplaypokemon.cpp \
    Interface/Graphics/ObjectGraphics/graphicstextarea.cpp \
    Interface/Graphics/Scene/pokebatlescenekernel.cpp \
    Interface/Graphics/ObjectGraphics/attaquebutton.cpp \
    Interface/Graphics/ObjectGraphics/attaquepanel.cpp \
    Interface/Graphics/ObjectGraphics/graphicsgif.cpp \
    Interface/Graphics/Scene/evolutionscene.cpp \
    Interface/Graphics/Scene/learnattaquescene.cpp \
    Exeption/noattaquetolearn_personalexception.cpp \
    Interface/Graphics/ObjectGraphics/learnattaquebutton.cpp \
    Interface/Graphics/ObjectGraphics/panellearnattaque.cpp

DISTFILES += \
    TODO
