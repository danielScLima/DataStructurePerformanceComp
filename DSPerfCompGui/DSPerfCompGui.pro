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





#win32: LIBS += -L$$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/ -lDataStructureComp

#INCLUDEPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug
#DEPENDPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug

#PRE_TARGETDEPS += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/libDataStructureComp.a

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/DataStructureComp.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/libDataStructureComp.a

LIBS += -Lsubmodules/dsPerformanceComp/DataStructureComp/debug/ -lDataStructureComp

#message( $$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/ )

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/ -lDataStructureComp
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/ -lDataStructureComp

#message( $$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/ )

 #INCLUDEPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/
 #DEPENDPATH += $$PWD/submodules/dsPerformanceComp/DataStructureComp/debug/

 #win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/libDataStructureComp.a
 #else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/submodules/dsPerformanceComp/DataStructureComp/debug/libDataStructureComp.a


