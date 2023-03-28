QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    cbasicfile.cpp \
    cconfigfile.cpp \
    cdirectories.cpp \
    cexception.cpp \
    cfilebuffer.cpp \
    cfilemanager.cpp \
    cfont.cpp \
    cfontresource.cpp \
    cgameapplication.cpp \
    cmediatoolkit.cpp \
    cresourcearchive.cpp \
    cresourcefile.cpp \
    cresourceindex.cpp \
    csdl_toolkit.cpp \
    ctaggedresource.cpp \
    main.cpp \
    cmainwindow.cpp

HEADERS += \
    cbasicfile.h \
    cconfigdata.h \
    cconfigfile.h \
    cdirectories.h \
    cexception.h \
    cfilebuffer.h \
    cfilemanager.h \
    cfont.h \
    cfontresource.h \
    cgameapplication.h \
    cmainwindow.h \
    cmediatoolkit.h \
    cresourcearchive.h \
    cresourcedata.h \
    cresourcefile.h \
    cresourceindex.h \
    csdl_toolkit.h \
    ctaggedresource.h \
    defines.h

FORMS += \
    cmainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
