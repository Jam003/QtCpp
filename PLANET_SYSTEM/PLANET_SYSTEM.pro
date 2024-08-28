QT       += core gui
QT       += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boundingbox.cpp \
    cube.cpp \
    graphicsitem.cpp \
    main.cpp \
    mainwindow.cpp \
    myopenglwidget.cpp \
    scenemanage.cpp \
    triangle.cpp

HEADERS += \
    boundingbox.h \
    cube.h \
    graphicsitem.h \
    mainwindow.h \
    myopenglwidget.h \
    scenemanage.h \
    triangle.h

FORMS += \
    mainwindow.ui

LIBS += -L"D:/Vendor/Debug" -lglad -lvmath
INCLUDEPATH += D:/Vendor/include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
