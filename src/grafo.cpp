#include "grafo.h"

Grafo::Grafo()
{
    id = 0;
}

void Grafo::operator+=(Porta *p)
{
    portas[id] = p;
    p->setId(id);
    id++;
}

void Grafo::addAresta(int u, int v)
{
    portas[u]->adcVizinho(v);
}

void Grafo::drawArestas(QPainter *p)
{
    QMap<int, Porta *>::iterator i;

    for(i = portas.begin(); i!= portas.end(); i++)
    {
        QVector<int> v = i.value()->vizinhos;
        int n = v.size();

        int x = i.value()->getX();
        int y = i.value()->getY();

        for(int j = 0; j < n; j++)
        {
            int id = v[j];
            int X = portas[id]->getX();
            int Y = portas[id]->getY();

            QLineF line(x, y, X, Y);
            p->drawLine(line);
        }
    }

}





