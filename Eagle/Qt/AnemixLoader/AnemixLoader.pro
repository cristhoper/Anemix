include(3rdparty/qextserialport/src/qextserialport.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LuxiaLoader
TEMPLATE = app

SOURCES += main.cpp\
	mainwindow.cpp \
	stage.cpp \
	transition.cpp \
	serialcontroller.cpp

HEADERS  += mainwindow.h\
	stage.h \
	transition.h \
	serialcontroller.h

RESOURCES += \
    resources.qrc

