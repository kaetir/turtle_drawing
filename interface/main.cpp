#include <QApplication>

#include "mywindows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWindows fenetre;
    fenetre.show();


    return app.exec();
}
