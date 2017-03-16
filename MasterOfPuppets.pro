#-------------------------------------------------
#
# Project created by QtCreator 2016-05-31T20:32:27
#
#-------------------------------------------------

QT       += core gui sql network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MasterOfPuppets
TEMPLATE = app


SOURCES += main.cpp\
        masterofpuppets.cpp \
    ai_conn.cpp \
    ai_teach.cpp \
    save_settings.cpp \
    zagranie.cpp \
    taktyka.cpp \
    db_conn.cpp \
    mt4_conn_svr.cpp \
    mt4_conn_task.cpp \
    mt4_conn_cli.cpp \
    klient.cpp \
    folderscanner.cpp

HEADERS  += masterofpuppets.h \
    ai_conn.h \
    ai_teach.h \
    save_settings.h \
    zagranie.h \
    taktyka.h \
    db_conn.h \
    mt4_conn_svr.h \
    mt4_conn_task.h \
    mt4_conn_cli.h \
    klient.h \
    folderscanner.h

FORMS    += masterofpuppets.ui

OTHER_FILES += *.sqlite

DISTFILES += \
    sqlsave.sqlite \
    todo.txt
