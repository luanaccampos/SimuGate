#ifndef GRAFO_H
#define GRAFO_H

#include <QMap>
#include <QPainter>
#include "porta.h"

class Grafo
{
    int id;
    QMap<int, Porta *> portas;
public:
    Grafo();
    void operator+=(Porta *p);
    void addAresta(int u, int v);
    void drawArestas(QPainter *p);
};

#endif // GRAFO_H
