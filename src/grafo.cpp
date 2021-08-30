#include "grafo.h"

Grafo::Grafo()
{}

void Grafo::operator+=(Porta *p)
{
    int id = p->getId();
    portas[id] = p;
}

Porta *Grafo::operator[](int i)
{
    return portas[i];
}

void Grafo::addAresta(int u, int v)
{
    int i = portas[v]->getVizinhos().indexOf(portas[u]);

    if(portas[u]->getTipo() == "L")
        throw 3;

    if(i == -1)
        portas[v]->adcVizinho(portas[u]);
    else
        portas[v]->removeVizinho(portas[u]);

    atualiza();
}

void Grafo::drawArestas(QPainter *p)
{
    QMap<int, Porta *>::iterator i;

    for(i = portas.begin(); i!= portas.end(); i++)
        i.value()->drawArestas(p);
}

void Grafo::dfs(Porta *r)
{
    atualizado[r] = true;

    QVector<Porta *> v = r->getVizinhos();

    for(int i = 0; i < v.size(); i++)
        if(!atualizado[v[i]])
            dfs(v[i]);

    r->atualiza();
}

void Grafo::atualiza()
{
    atualizado.clear();
    QMap<int, Porta *>::iterator i;
    QMap<Porta*, bool>::iterator j;

    for(i = portas.begin(); i != portas.end(); i++)
        atualizado[i.value()] = false;

    for(j = atualizado.begin(); j != atualizado.end(); j++)
        if(!j.value())
            dfs(j.key());
}

void Grafo::apaga(int id)
{
    Porta *x = portas.find(id).value();
    delete portas[id];
    portas.erase(portas.find(id));

    QMap<int, Porta *>::iterator i;

    for(i = portas.begin(); i != portas.end(); i++)
        i.value()->removeVizinho(x);

    atualiza();
}

void Grafo::grafo2File(QFile *arquivo)
{
    QMap<int, Porta*>::iterator i;

    QTextStream saida(arquivo);
    QString s;

    for(i = portas.begin(); i != portas.end(); i++)
    {
        s += i.value()->getTipo() + " " + QString::number(i.key()) + " ";
        s += QString::number(i.value()->getX()) + " " + QString::number(i.value()->getY()) + " "; // coordenadas

        QVector<Porta *> v = i.value()->getVizinhos();

        s += QString::number(v.size()); // qt de vizinhos

        for(int j = 0; j < v.size(); j++)
            s += " " + QString::number(v[j]->getId());

        s += '\n';
    }

    saida << s;
    (*arquivo).flush();
    (*arquivo).close();
}

void Grafo::clear()
{
    QMap<int, Porta *>::iterator i;

    for(i = portas.begin(); i != portas.end(); i++)
        delete i.value();

    portas.clear();
}







