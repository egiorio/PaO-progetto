#QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#INCLUDEPATH += /opt/Qt/5.3/Src/qtbase/include/QtWidgets
TARGET = PaO
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNING
QT += widgets
QT +=core gui
#QT += xml

QMAKE_CXXFLAGS += -std=c++11


INCLUDEPATH +=.

CONFIG += c++11
#CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        add.cpp \
        addmodifica.cpp \
        cercawidget.cpp \
        cercawidgetresult.cpp \
        dolce.cpp \
        main.cpp \
        mainwindow.cpp \
        model.cpp \
        primo.cpp \
        ricette.cpp \
        secondo.cpp \
        widget.cpp \
        xmlio.cpp

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

HEADERS += \
    add.h \
    addmodifica.h \
    cercawidget.h \
    cercawidgetresult.h \
    container.h \
    container1.h \
    deepptr.h \
    dolce.h \
    mainwindow.h \
    model.h \
    primo.h \
    ricette.h \
    secondo.h \
    widget.h \
    xmlio.h
