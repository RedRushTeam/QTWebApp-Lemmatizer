# This project demonstrates how to use QtWebAppLib by including the
# sources into this project.

TARGET = Demo1
TEMPLATE = app
QT = core network
CONFIG += console
QMAKE_CXXFLAGS += -std=c++17
CONFIG += c++17
HEADERS += \
           src/controller/logincontroller.h \
           src/global.h \
           src/requestmapper.h \
           src/controller/dumpcontroller.h \
           src/controller/templatecontroller.h \
           src/controller/formcontroller.h \
           src/controller/fileuploadcontroller.h \
           src/controller/sessioncontroller.h

SOURCES += src/main.cpp \
           src/controller/logincontroller.cpp \
           src/global.cpp \
           src/requestmapper.cpp \
           src/controller/dumpcontroller.cpp \
           src/controller/templatecontroller.cpp \
           src/controller/formcontroller.cpp \
           src/controller/fileuploadcontroller.cpp \
           src/controller/sessioncontroller.cpp

OTHER_FILES += etc/* etc/docroot/* etc/templates/* etc/ssl/* logs/*

DISTFILES += ../CHANGELOG.txt ../LICENSE.txt ../README.txt

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../QtWebApp/logging/logging.pri)
include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)


LIBS += -L$$PWD/../../../../../../RGD/RussianGrammaticalDictionary/lib64/ -llemmatizator
LIBS += -L$$PWD/../../../../../../RGD/RussianGrammaticalDictionary/lib64/ -lSolarix_Grammar_Engine

#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\lemmatizator.dll"
#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\solarix_grammar_engine.dll"

INCLUDEPATH += $$PWD/../../../../../../RGD/RussianGrammaticalDictionary/include/lem/solarix/pro
DEPENDPATH += $$PWD/../../../../../../RGD/RussianGrammaticalDictionary/include/lem/solarix/pro

INCLUDEPATH += $$PWD/../../../../../../RGD/RussianGrammaticalDictionary/include/lem/solarix
DEPENDPATH += $$PWD/../../../../../../RGD/RussianGrammaticalDictionary/include/lem/solarix

win32: LIBS += -L$$PWD/../../../../../../re2/Qlib/ -lre2

INCLUDEPATH += $$PWD/../../../../../../re2/include
DEPENDPATH += $$PWD/../../../../../../re2/include
