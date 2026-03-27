#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class MainWindow;
class DisplayWindow;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(MainWindow *mainWin,
               DisplayWindow *displaWin
               );


};

#endif // CONTROLLER_H
