######################################################################
# Automatically generated by qmake (2.01a) Tue Nov 25 20:47:30 2008
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input

HEADERS += ticketDetail.h \
	qtMushi.h \
	taskFinder.h
	
SOURCES += main.cpp \
	ticketDetail.cpp \
	qtMushi.cpp \
	taskFinder.cpp

RESOURCES += attach.qrc


INCLUDEPATH += ../edit_html
DEPENDPATH += ../edit_html

INCLUDEPATH += ../libhtml
DEPENDPATH += ../libhtml

INCLUDEPATH += ../libhtml/include
DEPENDPATH += ../libhtml/include


LIBS += ../all_os_libs/libtidy.a
LIBS += ../edit_html/libEdithtml.a
QT += xml
QT += sql
QT += network
QT += webkit
