#include "false.h"

False::False(int x, int y, QWidget *parent) : Porta(x, y, parent)
{
    QPixmap imagem("imagens/false.png");
    setPixmap(imagem);
    setGeometry(x, y, 51, 52);
}

QString False::getTipo()
{
    return "F";
}
