QT -= gui

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

SOURCES += main.cpp \
    Type/abstracttype.cpp \
    Type/tabletypes.cpp \
    Type/typeacier.cpp \
    Type/doubletype.cpp \
    Type/typecombat.cpp \
    Type/typedragon.cpp \
    Type/typeeau.cpp \
    Type/typeelectrique.cpp \
    Type/typefeu.cpp \
    Type/typefee.cpp \
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
    Type/typevol.cpp

HEADERS += \
    Type/abstracttype.h \
    Type/tabletypes.h \
    Type/typeacier.h \
    Type/doubletype.h \
    Type/typecombat.h \
    Type/typedragon.h \
    Type/typeeau.h \
    Type/typeelectrique.h \
    Type/typefeu.h \
    Type/typefee.h \
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
    Type/typevol.h
