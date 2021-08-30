#include "and.h"

And::And(int x, int y, int id, QWidget *parent) : Porta(x, y, id, parent)
{
    this->x -= 35;
    this->y -= 44;
    QPixmap imagem("imagens/and.png");
    setPixmap(imagem);
    setGeometry(x-35, y-44, 70, 71);
}

QString And::getTipo()
{
    return "A";
}

void And::selected()
{
    QPixmap imagem("imagens/andShadow.png");
    setPixmap(imagem);
}

void And::unSelected()
{
    QPixmap imagem("imagens/and.png");
    setPixmap(imagem);
}

void And::atualiza()
{
    bool f = false;
    int k, n;

    k = 0;
    n = vizinhos.size();

    for(int i = 0; i < n; i++)
    {
        int saida = vizinhos[i]->getSaida();

        if(saida == 0)
            f = true;
        if(saida == -1)
            k++;
    }

    if(f)
        saida = 0;
    else
    {
        if(k == n)
            saida = -1;
        else
            saida = 1;
    }
}

