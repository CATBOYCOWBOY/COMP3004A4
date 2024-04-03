QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  computerview.cpp \
  eegsensorpool.cpp \
  main.cpp \
  mainwindow.cpp \
  SensorPool.cpp \
  Session.cpp \
    timecontroller.cpp \
    timeupdater.cpp
  neuresetcontroller.cpp \
  treatmentcontroller.cpp

HEADERS += \
  computerview.h \
  constants.h \
  eegsensorpool.h \
  mainwindow.h \
  constants.h \
  SensorPool.h \
  Session.h \
  timecontroller.h \
  timeupdater.h
  neuresetController.h \
  treatmentcontroller.h

FORMS += \
  computerview.ui \
  mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  resources.qrc
