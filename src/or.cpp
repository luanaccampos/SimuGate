#include "or.h"

Or::Or(int x, int y, QWidget *parent) : Porta(x, y, parent)
{
    QPixmap imagem("imagens/or.png");
    setPixmap(imagem);
    setGeometry(x, y, 50, 49);
}

QString Or::getTipo()
{
    return "O";
}
