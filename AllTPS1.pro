TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Chapitre2_TypesDeVariables.c \
        Chapitre4_Graphique.c \
        Chapitre5_Grapheur.c \
        Chapitre5_StructuresDeControle.c \
        Chapitre7_LesTableaux.c \
        Chapitre9_Strings.c \
        ext/ez-draw.c \
        main.c

INCLUDEPATH += ../include /opt/X11/include

LIBS +=  -lX11 -lXext -L../lib -L/opt/X11/lib

HEADERS += \
    Chapitre2_TypesDeVariables.h \
    Chapitre4_Graphique.h \
    Chapitre5_Grapheur.h \
    Chapitre5_StructuresDeControle.h \
    Chapitre7_LesTableaux.h \
    Chapitre7_PyramideData.h \
    Chapitre9_Strings.h \
    ext/ez-draw.h

DISTFILES +=
