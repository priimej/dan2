#include "mainwindow.h"
#include "displaywindow.h"
#include "controller.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    // start the app
    QApplication a(argc, argv);

    // the two windows we created
    MainWindow mw;
    DisplayWindow dw;

    // the controller that binds them (and more) together
    Controller controller(&mw, &dw);

    mw.show();
    dw.show();

    return QCoreApplication::exec();
}
