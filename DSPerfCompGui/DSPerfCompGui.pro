QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#Inserting the include paths
INCLUDEPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/
INCLUDEPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/headers/
INCLUDEPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/sources/

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp

HEADERS += \
    mainwindow.h \
    mainwindow2.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#This is the end of default .pro file


LIBS += -Lsubmodules/dsPerformanceComp/DataStructureComp/debug/ -lDataStructureComp

