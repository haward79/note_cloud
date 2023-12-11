#ifndef MAIN_H
#define MAIN_H

#include <QApplication>
#include <QObject>
#include <QTime>
#include <QMenu>
#include <QPropertyAnimation>
#include <QSystemTrayIcon>
#include "Sleep.h"
#include "Settings.h"
#include "MainWindow.h"
#include "AboutWindow.h"
#include "NoteWelcomeWindow.h"
#include "NoteSettingWindow.h"

class Main : QObject
{
    Q_OBJECT

public:
    static quint8 WELCOME_SECOND;
    Main(QApplication&);

private:
    QApplication& app;
    Settings settings;
    NoteWelcomeWindow noteWelcomeWindow;
    NoteSettingWindow noteSettingWindow;
    MainWindow *mainWindow;
    AboutWindow aboutWindow;
    QSystemTrayIcon tray;
    QMenu trayMenu;
    QAction trayAction_about;
    QAction trayAction_quit;
    static void window_fadeIn(QWidget&);
    void show_noteWelcomeWindow();
    void check_initSetting();
    void start_tray();
};

#endif // MAIN_H
