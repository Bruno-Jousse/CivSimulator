#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T18:01:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CivSimulation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += main.cpp src/World.cpp src/Agent.cpp src/Building.cpp src/Machine.cpp src/Metal.cpp src/Soldier.cpp src/Worker.cpp \
    src/Entity.cpp src/Headquarter.cpp src/Healthbar.cpp src/Grid.cpp \
    src/Resource.cpp \
    src/TimeManager.cpp \
    src/RandomManager.cpp


HEADERS += src/World.h src/Agent.h src/Building.h src/Headquarter.h src/Machine.h src/Metal.h src/Soldier.h src/Worker.h \
    src/Entity.h src/Healthbar.h src/Grid.h \
    src/Resource.h \
    src/TimeManager.h \
    src/RandomManager.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
