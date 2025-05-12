QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    auditorium.cpp \
    auditoriummanagement.cpp \
    bookingdate.cpp \
    calender.cpp \
    calendermanager.cpp \
    date.cpp \
    main.cpp \
    month.cpp \
    year.cpp

HEADERS += \
    MainWindow.h \
    auditorium.h \
    auditoriummanagement.h \
    bookingdate.h \
    calender.h \
    calendermanager.h \
    date.h \
    month.h \
    year.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
