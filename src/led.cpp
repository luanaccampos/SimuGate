#include "led.h"

Led::Led(int x, int y, int id, QWidget *parent) : Porta(x, y, id, parent)
{
    this->x -= 43;
    this->y -= 43;
    QPixmap imagem("imagens/led0.png");
    setPixmap(imagem);
    setGeometry(x-43, y-43, 86, 86);
}

QString Led::getTipo()
{
    return "L";
}

void Led::selected()
{
    QString s = "imagens/led";

    if(saida == -1)
        s += "0";
    if(saida == 0)
        s += "1";
    if(saida == 1)
        s += "2";

    s += "Shadow.png";

    QPixmap imagem(s);
    setPixmap(imagem);
}

void Led::unSelected()
{
    QString s = "imagens/led";

    if(saida == -1)
        s += "0";
    if(saida == 0)
        s += "1";
    if(saida == 1)
        s += "2";

    s += ".png";

    QPixmap imagem(s);
    setPixmap(imagem);
}

void Led::atualiza()
{
    if(vizinhos.size() > 0)
        saida = vizinhos[0]->getSaida();
    else
        saida = -1;

    unSelected();
}

void Led::adcVizinho(Porta *x)
{
    if(vizinhos.size() == 0)
        vizinhos.push_back(x);
    else
        throw 2;
}
