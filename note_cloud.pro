QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AboutWindow.cpp \
    Main.cpp \
    Note.cpp \
    NoteEditWindow.cpp \
    NoteSettingWindow.cpp \
    NoteWelcomeWindow.cpp \
    Settings.cpp \
    Sleep.cpp \
    WebDAVClient.cpp \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    AboutWindow.h \
    Main.h \
    MainWindow.h \
    Note.h \
    NoteEditWindow.h \
    NoteSettingWindow.h \
    NoteWelcomeWindow.h \
    Settings.h \
    Sleep.h \
    WebDAVClient.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
