#include "Main.h"

quint8 Main::WELCOME_SECOND = 3;

Main::Main(QApplication& app) : app(app), noteSettingWindow(settings)
{
    this->show_noteWelcomeWindow();
    this->check_initSetting();
    this->start_tray();
}

void Main::window_fadeIn(QWidget& window)
{
    QPropertyAnimation opacity_animation = QPropertyAnimation(&window, "windowOpacity");

    opacity_animation.setDuration(Main::WELCOME_SECOND * 1000);
    opacity_animation.setStartValue(0.0);
    opacity_animation.setEndValue(1.0);
    opacity_animation.setEasingCurve(QEasingCurve::OutQuad);
    opacity_animation.start(QAbstractAnimation::KeepWhenStopped);
}

void Main::show_noteWelcomeWindow()
{
    this->noteWelcomeWindow.show();

    this->window_fadeIn(this->noteWelcomeWindow);
    Sleep::sleep(Main::WELCOME_SECOND + 1);
    noteWelcomeWindow.close();
}

void Main::check_initSetting()
{
    while(!this->settings.is_loaded())
    {
        if(this->noteSettingWindow.isHidden())
        {
            qDebug() << "Please initialize settings first.";
            this->noteSettingWindow.show();
        }

        Sleep::msleep(500);
    }

    qDebug() << "Initial settings check passed.";
    this->mainWindow = new MainWindow();
}

void Main::start_tray()
{
    this->trayAction_about.setText("About");
    this->trayAction_quit.setText("Quit");

    this->trayMenu.addAction(&this->trayAction_about);
    this->trayMenu.addAction(&this->trayAction_quit);

    this->tray.setIcon(QIcon(QPixmap("icon.png")));
    this->tray.setToolTip("Note");
    this->tray.setContextMenu(&this->trayMenu);
    this->tray.show();

    QObject::connect(&this->tray, &QSystemTrayIcon::activated, this->mainWindow, &MainWindow::show);
    QObject::connect(&this->trayAction_about, &QAction::triggered, &this->aboutWindow, &AboutWindow::show);
    QObject::connect(&this->trayAction_quit, &QAction::triggered, &this->app, &QApplication::quit);
}
