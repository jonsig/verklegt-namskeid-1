#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:34:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core sql
TARGET = week3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    repositories/computerrepository.cpp \
    repositories/relationrepository.cpp \
    repositories/scientistrepository.cpp \
    services/computerservice.cpp \
    services/relationservice.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    addscientist.cpp \
    addcomputer.cpp \
    addrelation.cpp \
    editcomputer.cpp \
    editscientist.cpp


HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/relationrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/relationservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h \
    addscientist.h \
    addcomputer.h \
    addrelation.h \
    editcomputer.h \
    editscientist.h


FORMS    += mainwindow.ui \
    addscientist.ui \
    addcomputer.ui \
    addrelation.ui \
    editcomputer.ui \
    editscientist.ui
