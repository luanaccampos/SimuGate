#ifndef GRAFO_H
#define GRAFO_H

#include <QMap>
#include <QPainter>
#include "porta.h"

class Grafo
{
    QMap<int, Porta *> portas;
    QMap<Porta *, bool> atualizado;
public:
    Grafo();
    void operator+=(Porta *p);
    Porta *operator[](int i);
    void addAresta(int u, int v);
    void drawArestas(QPainter *p);
    void dfs(Porta *r);
    void atualiza();
    void apaga(int id);
    void grafo2File(QFile *arquivo);
    void clear();
};

#endif // GRAFO_H
