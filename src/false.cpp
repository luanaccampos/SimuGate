#include "false.h"

False::False(int x, int y, int id, QWidget *parent) : Porta(x, y, id, parent)
{
    this->x -= 44;
    this->y -= 44;
    QPixmap imagem("imagens/false.png");
    setPixmap(imagem);
    setGeometry(x-44, y-44, 88, 88);
    saida = 0;
}

QString False::getTipo()
{
    return "F";
}

void False::selected()
{
    QPixmap imagem("imagens/falseShadow.png");
    setPixmap(imagem);
}

void False::unSelected()
{
    QPixmap imagem("imagens/false.png");
    setPixmap(imagem);
}

void False::adcVizinho(Porta *x)
{
    throw 1;
}
