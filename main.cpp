#include "MainWindow.h"

#include <QApplication>
#include "Main.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Main m(app);

    app.setWindowIcon(QIcon("icon.png"));
    app.setQuitOnLastWindowClosed(false);

    return app.exec();
}
