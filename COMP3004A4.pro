QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  Logs.cpp \
  computerview.cpp \
  eegsensor.cpp \
  main.cpp \
  mainwindow.cpp \
  Session.cpp \
  qcustomplot.cpp \
  timecontroller.cpp \
  timeupdater.cpp \
  menucontroller.cpp \
  neuresetcontroller.cpp \
  treatmentcontroller.cpp

HEADERS += \
  Logs.h \
  computerview.h \
  constants.h \
  eegsensor.h \
  mainwindow.h \
  constants.h \
  Session.h \
  qcustomplot.h \
  timecontroller.h \
  timeupdater.h \
  menucontroller.h \
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

DISTFILES += \
    logs.txt
