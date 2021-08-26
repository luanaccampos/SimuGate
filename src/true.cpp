#include "true.h"

True::True(int x, int y, QWidget *parent) : Porta(x, y, parent)
{
    QPixmap imagem("imagens/true.png");
    setPixmap(imagem);
    setGeometry(x, y, 51, 52);
}

QString True::getTipo()
{
    return "T";
}
