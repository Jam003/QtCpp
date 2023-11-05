QT       += core gui
QT       += sql
QT       += multimedia
QT       += multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    playlist.cpp \
    spectrumwidget.cpp \
    tprocess.cpp

HEADERS += \
    mainwindow.h \
    playlist.h \
    spectrumwidget.h \
    tprocess.h

FORMS += \
    mainwindow.ui \
    playlist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc



unix|win32: LIBS += -L$$PWD/lib/x64/ -lfmod_vc

INCLUDEPATH += $$PWD/inc
DEPENDPATH += $$PWD/inc
