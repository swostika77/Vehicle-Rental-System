QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookvehicle.cpp \
    customer.cpp \
    feedback.cpp \
    front.cpp \
    historydialog.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    viewfeedback.cpp

HEADERS += \
    bookvehicle.h \
    customer.h \
    feedback.h \
    front.h \
    historydialog.h \
    login.h \
    mainwindow.h \
    register.h \
    viewfeedback.h

FORMS += \
    bookvehicle.ui \
    customer.ui \
    feedback.ui \
    front.ui \
    historydialog.ui \
    login.ui \
    mainwindow.ui \
    register.ui \
    viewfeedback.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
