# -------------------------------------------------
# Project created by QtCreator 2009-02-12T10:10:10
# ------------------------------------------------
CONFIG += qt
QT += script
QT += network
QT -= gui
TARGET = build//bin/MushiServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += utils.cpp \
    URLHandlers.cpp \
    sqlite3.c \
    MushiSetup.cpp \
    MushiSession.cpp \
    MushiServer.cpp \
    MushiDBResult.cpp \
    MushiDB.cpp \
    MushiConfig.cpp \
    MushiCommand.cpp \
    mongoose.c \
    commands/FindTaskCommand.cpp \
    commands/EditTaskCommand.cpp \
    commands/DeleteTaskCommand.cpp \
    commands/AddTaskCommand.cpp \
    ../lib_json/json_writer.cpp \
    ../lib_json/json_value.cpp \
    ../lib_json/json_reader.cpp \
    main.cpp \
    MushiScriptGlobal.cpp \
    MushiScriptConn.cpp \
    MushiScriptDB.cpp \
    commands/ScriptCommand.cpp \
    ScriptEngine.cpp \
    smtp.cpp \
    commands/GetStatusesCommand.cpp
HEADERS += utils.h \
    URLHandlers.h \
    sqlite3.h \
    MushiSetup.h \
    MushiSession.h \
    MushiServer.h \
    MushiDBResult.h \
    MushiDB.h \
    MushiConfig.h \
    MushiCommand.h \
    mongoose.h \
    commands/FindTaskCommand.h \
    commands/EditTaskCommand.h \
    commands/DeleteTaskCommand.h \
    commands/AddTaskCommand.h \
    ../lib_json/writer.h \
    ../lib_json/value.h \
    ../lib_json/reader.h \
    ../lib_json/json_batchallocator.h \
    ../lib_json/json.h \
    ../lib_json/forwards.h \
    ../lib_json/config.h \
    ../lib_json/autolink.h \
    MushiScriptConn.h \
    MushiScriptDB.h \
    MushiScriptGlobal.h \
    commands/ScriptCommand.h \
    ScriptEngine.h \
    smtp.h \
    commands/GetStatusesCommand.h
