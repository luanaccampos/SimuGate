#include "true.h"

True::True(int x, int y, int id, QWidget *parent) : Porta(x, y, id, parent)
{
    this->x -= 44;
    this->y -= 44;
    QPixmap imagem("imagens/true.png");
    setPixmap(imagem);
    setGeometry(x-44, y-44, 88, 88);
    saida = 1;
}

QString True::getTipo()
{
    return "T";
}

void True::selected()
{
    QPixmap imagem("imagens/trueShadow.png");
    setPixmap(imagem);
}

void True::unSelected()
{
    QPixmap imagem("imagens/true.png");
    setPixmap(imagem);
}

void True::adcVizinho(Porta *x)
{
    throw 1;
}
