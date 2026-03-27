// controller.cpp
#include "controller.h"
#include "mainwindow.h"
#include "displaywindow.h"

Controller::Controller(MainWindow *mainWin,
                       DisplayWindow *displayWin)
{
    // connecting the two together in the controller object
    connect(mainWin, &MainWindow::pass_json,
            displayWin, &DisplayWindow::recieve_json);
}