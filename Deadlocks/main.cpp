#include "deadlocks.h"
//#include <QApplication>
//#include <QDebug>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
    Deadlocks w;
//    w.show();

    if (argc > 1)
    {
        if (QString::fromStdString(argv[1]) == "-d")
        {
            w.tryMakeDeadLock(false);
        }
    }

    w.tryMakeDeadLock(true);

    while(1)
    {

    }
//    return a.exec();
}
