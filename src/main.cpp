#include <QApplication>
#include "janelaprincipal.h"

int main(int argc, char*argv[])
{
    QApplication app(argc, argv);
    janelaPrincipal j;
    j.show();

    return app.exec();
}
