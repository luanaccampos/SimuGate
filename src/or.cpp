#include "or.h"

Or::Or(int x, int y, int id, QWidget *parent) : Porta(x, y, id, parent)
{
    this->x -= 44;
    this->y -= 44;
    QPixmap imagem("imagens/or.png");
    setPixmap(imagem);
    setGeometry(x-44, y-44, 89, 88);
}

QString Or::getTipo()
{
    return "O";
}

void Or::selected()
{
    QPixmap imagem("imagens/orShadow.png");
    setPixmap(imagem);
}

void Or::unSelected()
{
    QPixmap imagem("imagens/or.png");
    setPixmap(imagem);
}

void Or::atualiza()
{
    bool v = false;
    int k, n;

    k = 0;
    n = vizinhos.size();

    for(int i = 0; i < n; i++)
    {
        int saida = vizinhos[i]->getSaida();

        if(saida == 1)
            v = true;
        if(saida == -1)
            k++;
    }

    if(v)
        saida = 1;
    else
    {
        if(k == n)
            saida = -1;
        else
            saida = 0;
    }
}
