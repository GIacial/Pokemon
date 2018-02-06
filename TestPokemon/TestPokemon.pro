QT -= gui
QT += testlib

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
    Pokemon/Attaque/abstractattaque.h \
    Pokemon/Pokemon/abstractpokemon.h \
    Pokemon/Statut/abstractstatut.h \
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
    Test/Type/test_typeacier.h

SOURCES += \
    Pokemon/Attaque/abstractattaque.cpp \
    Pokemon/Pokemon/abstractpokemon.cpp \
    Pokemon/Statut/abstractstatut.cpp \
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
    Test/Type/test_typeacier.cpp \
    main.cpp
