QT       += core gui openglwidgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/model.cc \
    ../controller/controller.cc \
    glwidget.cc \
    view.cc \
    ../main.cc \
    qtgifimage/src/3rdParty/giflib/dgif_lib.c \
    qtgifimage/src/3rdParty/giflib/egif_lib.c \
    qtgifimage/src/3rdParty/giflib/gif_err.c \
    qtgifimage/src/3rdParty/giflib/gif_font.c \
    qtgifimage/src/3rdParty/giflib/gif_hash.c \
    qtgifimage/src/3rdParty/giflib/gifalloc.c \
    qtgifimage/src/3rdParty/giflib/quantize.c \
    qtgifimage/src/gifimage/qgifimage.cpp

HEADERS += \
    ../utils.h \
    ../model/model.h \
    ../controller/controller.h \
    gif.h \
    glwidget.h \
    view.h \
    qtgifimage/src/3rdParty/giflib/gif_hash.h \
    qtgifimage/src/3rdParty/giflib/gif_lib.h \
    qtgifimage/src/3rdParty/giflib/gif_lib_private.h \
    qtgifimage/src/gifimage/qgifglobal.h \
    qtgifimage/src/gifimage/qgifimage.h \
    qtgifimage/src/gifimage/qgifimage_p.h

FORMS += \
    view.ui

INCLUDEPATH += view

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    qtgifimage/src/gifimage/doc/snippets/doc_src_qtgifimage.pro \
    qtgifimage/src/gifimage/gifimage.pro

DISTFILES += \
    qtgifimage/src/3rdParty/giflib.pri \
    qtgifimage/src/3rdParty/giflib/AUTHORS \
    qtgifimage/src/3rdParty/giflib/COPYING \
    qtgifimage/src/3rdParty/giflib/README \
    qtgifimage/src/gifimage/doc/qtgifimage.qdocconf \
    qtgifimage/src/gifimage/doc/src/examples.qdoc \
    qtgifimage/src/gifimage/doc/src/index.qdoc \
    qtgifimage/src/gifimage/doc/src/qtgifimage.qdoc \
    qtgifimage/src/gifimage/doc/src/usage.qdoc \
    qtgifimage/src/gifimage/qtgifimage.pri
