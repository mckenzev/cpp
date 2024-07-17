QT += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++ 17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE =0x060000    #disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    include/utils.cc \
    include/utils_with_qt.cc \
    controller/controller.cc \
    model/model_calculation.cc \
    model/model_matrix_graph.cc \
    model/model.cc \
    view/view.cc \
    view/view_calculation.cc \
    view/view_graph.cc

HEADERS += \
    include/utils.h \
    include/utils_with_qt.h \
    model/model.h \
    model/model_calculation.h \
    model/model_matrix_graph.h \
    view/view.h \
    view/view_calculation.h \
    view/view_graph.h \
    controller/controller.h

FORMS += \
    view/view.ui

#Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path) : INSTALLS += target
