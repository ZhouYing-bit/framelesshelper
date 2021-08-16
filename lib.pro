TARGET = $$qtLibraryTarget(FramelessHelper)
TEMPLATE = lib
win32: DLLDESTDIR = $$OUT_PWD/bin
else: unix: DESTDIR = $$OUT_PWD/bin
QT += gui-private
CONFIG += c++17 strict_c++ utf8_source warn_on
DEFINES += \
    QT_NO_CAST_FROM_ASCII \
    QT_NO_CAST_TO_ASCII \
    QT_NO_KEYWORDS \
    QT_DEPRECATED_WARNINGS \
    QT_DISABLE_DEPRECATED_BEFORE=0x060100 \
    FRAMELESSHELPER_BUILD_LIBRARY
HEADERS += \
    framelesshelper_global.h \
    framelesshelper.h \
    framelesswindowsmanager.h \
    utilities.h
SOURCES += \
    framelesshelper.cpp \
    framelesswindowsmanager.cpp \
    utilities.cpp
qtHaveModule(quick) {
    QT += quick
    HEADERS += framelessquickhelper.h
    SOURCES += framelessquickhelper.cpp
}
win32 {
    DEFINES += \
        WIN32_LEAN_AND_MEAN \
        _CRT_SECURE_NO_WARNINGS \
        UNICODE \
        _UNICODE \
        WINVER=0x0A000007 \
        _WIN32_WINNT=0x0A000007
    HEADERS += framelesshelper_win32.h
    SOURCES += \
        utilities_win32.cpp \
        framelesshelper_win32.cpp
    LIBS += -ldwmapi
    LIBS += -lUser32
    LIBS += shell32.lib
    RC_FILE = framelesshelper.rc
}
