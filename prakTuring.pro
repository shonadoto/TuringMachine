QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcharacterwindow.cpp \
    backend.cpp \
    deletecharwindow.cpp \
    deletecondwindow.cpp \
    editcellwindow.cpp \
    error.cpp \
    inpwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addcharacterwindow.h \
    backend.h \
    deletecharwindow.h \
    deletecondwindow.h \
    editcellwindow.h \
    error.h \
    inpwindow.h \
    mainwindow.h

FORMS += \
    addcharacterwindow.ui \
    deletecharwindow.ui \
    deletecondwindow.ui \
    editcellwindow.ui \
    error.ui \
    inpwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
