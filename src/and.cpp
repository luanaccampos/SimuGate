#include "and.h"

And::And(int x, int y, QWidget *parent) : Porta(x, y, parent)
{
    QPixmap imagem("imagens/and.png");
    setPixmap(imagem);
    setGeometry(x, y, 50, 50);
}

QString And::getTipo()
{
    return "A";
}
