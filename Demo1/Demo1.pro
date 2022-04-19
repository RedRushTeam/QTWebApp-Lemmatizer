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
           src/controller/sessioncontroller.h \
           src/controller/analyzer.h \
           src/controller/container_class_interface.h \
           src/controller/list_of_functions.h \
           src/controller/list_of_types.h \
           src/controller/math_core.h \
           src/controller/parser.h \
           src/controller/piecewise_container_class.h \
           src/controller/sparce_container_class.h \


SOURCES += src/main.cpp \
           src/controller/logincontroller.cpp \
           src/global.cpp \
           src/requestmapper.cpp \
           src/controller/dumpcontroller.cpp \
           src/controller/templatecontroller.cpp \
           src/controller/formcontroller.cpp \
           src/controller/fileuploadcontroller.cpp \
           src/controller/sessioncontroller.cpp \
           src/controller/analyzer.cpp \
           src/controller/container_class_interface.cpp \
           src/controller/list_of_functions.cpp \
           src/controller/math_core.cpp \
           src/controller/parser.cpp \
           src/controller/piecewise_container_class.cpp \
           src/controller/sparce_container_class.cpp

OTHER_FILES += etc/* etc/docroot/* etc/templates/* etc/ssl/* logs/*

DISTFILES += ../CHANGELOG.txt ../LICENSE.txt ../README.txt

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(D:/QTWebApp-Lemmatizer/QtWebApp/logging/logging.pri)
include(D:/QTWebApp-Lemmatizer/QtWebApp/httpserver/httpserver.pri)
include(D:/QTWebApp-Lemmatizer/QtWebApp/templateengine/templateengine.pri)


#LIBS += -L"D:/dependencies/RGD/RussianGrammaticalDictionary/lib64/" -llemmatizator
#LIBS += -L"D:/dependencies/RGD/RussianGrammaticalDictionary/lib64/" -lSolarix_Grammar_Engine

#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\lemmatizator.dll"
#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\solarix_grammar_engine.dll"

#INCLUDEPATH += "D:/dependencies/RGD/RussianGrammaticalDictionary/include/lem/solarix/pro"
#DEPENDPATH += "D:/dependencies/RGD/RussianGrammaticalDictionary/include/lem/solarix/pro"

#INCLUDEPATH += "D:/dependencies/RGD/RussianGrammaticalDictionary/include/lem/solarix"
#DEPENDPATH += "D:/dependencies/RGD/RussianGrammaticalDictionary/include/lem/solarix"

#win32: LIBS += -L"D:/dependencies/re2/Qlib/" -lre2

#INCLUDEPATH += "D:/dependencies/re2/include"
#DEPENDPATH += "D:/dependencies/re2/include"

LIBS += -L"C:/RGD/RussianGrammaticalDictionary/lib64/" -llemmatizator
LIBS += -L"C:/RGD/RussianGrammaticalDictionary/lib64/" -lSolarix_Grammar_Engine

#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\lemmatizator.dll"
#LIBS += "C:\RGD\RussianGrammaticalDictionary\lib64\solarix_grammar_engine.dll"

INCLUDEPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem/solarix/pro"
DEPENDPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem/solarix/pro"

INCLUDEPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem/solarix"
DEPENDPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem/solarix"

win32: LIBS += -L"C:/re2/Qlib/" -lre2

INCLUDEPATH += "C:/re2/include"
DEPENDPATH += "C:/re2/include"



INCLUDEPATH += "C:/tsl/include"
DEPENDPATH += "C:/tsl/include"

INCLUDEPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem"
DEPENDPATH += "C:/RGD/RussianGrammaticalDictionary/include/lem"

INCLUDEPATH += "D:/local/boost_1_75_0/stage/lib"
DEPENDPATH += "D:/local/boost_1_75_0/stage/lib"

INCLUDEPATH += "D:/local/boost_1_75_0"
DEPENDPATH += "D:/local/boost_1_75_0"

LIBS += -L"C:/re2/Rlib" -lre2

LIBS += -L"D:/local/boost_1_75_0/stage/lib" -lboost_iostreams-vc142-mt-gd-x64-1_75

INCLUDEPATH += "C:\RGD\SVD MATH\eigen-3.3.8\Eigen"
DEPENDPATH += "C:\RGD\SVD MATH\eigen-3.3.8\Eigen"

INCLUDEPATH += "D:\QTWebApp-Lemmatizer\Demo1\src\MKL\include"
DEPENDPATH += "D:\QTWebApp-Lemmatizer\Demo1\src\MKL\include"

LIBS += -L"D:\QTWebApp-Lemmatizer\Demo1\src\MKL\lib" -lmkl_core

LIBS += -L"D:\QTWebApp-Lemmatizer\Demo1\src\MKL\lib" -lmkl_rt
LIBS += -L"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\SDK\ScopeCppSDK\vc15\SDK\lib" -lOleAut32
