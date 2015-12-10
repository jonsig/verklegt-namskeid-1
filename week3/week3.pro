#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:34:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    utilities/scientistcomparator.cpp \
    utilities/scientistsorting.cpp \
    utilities/utils.cpp

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
    utilities/scientistcomparator.h \
    utilities/scientistsorting.h \
    utilities/utils.h

FORMS    += mainwindow.ui
