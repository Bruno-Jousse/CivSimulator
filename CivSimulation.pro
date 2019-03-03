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

SOURCES +=  main.cpp \
            src/model/World.cpp src/model/Agent.cpp src/model/Headquarter.cpp src/model/Metal.cpp src/model/Resource.cpp src/model/Soldier.cpp src/model/Worker.cpp src/model/Entity.cpp \
            src/model/RandomManager.cpp src/controller/Simulator.cpp \
            src/view/Agent.cpp src/view/Healthbar.cpp src/view/Soldier.cpp src/view/Building.cpp src/view/Machine.cpp src/view/Worker.cpp src/view/Entity.cpp src/view/Metal.cpp src/view/World.cpp src/view/Headquarter.cpp src/view/Resource.cpp \
    src/view/TimeManager.cpp \
    src/view/FactoryViewItem.cpp \
    src/model/Healthbar.cpp src/model/Grid.cpp


HEADERS +=  src/model/World.h src/model/Agent.h src/model/Headquarter.h src/model/Metal.h src/model/Resource.h src/model/Soldier.h src/model/Worker.h src/model/Entity.h \
            src/controller/Simulator.h src/model/RandomManager.h \
            src/view/Agent.h src/view/Healthbar.h src/view/Soldier.h src/view/Building.h src/view/Machine.h src/view/Worker.h src/view/Entity.h src/view/Metal.h src/view/World.h src/view/Headquarter.h src/view/Resource.h \
    src/view/TimeManager.h \
    src/view/FactoryViewItem.h \
    src/model/Healthbar.h src/model.Grid.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
