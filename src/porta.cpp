#include "porta.h"

Porta::Porta(int x, int y, int id, QWidget *parent) : QLabel(parent)
{
    saida = -1;
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->id = id;

    setStyleSheet("background-color:transparent;");
    setVisible(true);
    connect(this, SIGNAL(clicked(int)), parent, SLOT(itwasclicked(int)));
    connect(this, SIGNAL(moved()), parent, SLOT(up()));
}

void Porta::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
        this->move(mapToParent(event->pos() - offset));

    QPoint p = mapTo(parent, event->pos());

    x = p.x() - event->x();
    y = p.y() - event->y();

    emit moved();
}

void Porta::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
    emit clicked(id);
}

int Porta::getId()
{
    return id;
}

void Porta::adcVizinho(Porta *x)
{
    vizinhos.push_back(x);
}

void Porta::removeVizinho(Porta *x)
{
    int i = vizinhos.indexOf(x);
    if(i != -1)
        vizinhos.remove(i);
}

int Porta::getX()
{
    return x;
}

int Porta::getY()
{
    return y;
}

int Porta::getSaida()
{
    return saida;
}

QVector<Porta *> Porta::getVizinhos()
{
    return vizinhos;
}

void Porta::drawArestas(QPainter *p)
{
    int X, Y;
    int n = vizinhos.size();

    for(int i = 0; i < n; i++)
    {
        int s = vizinhos[i]->getSaida();
        QPen pen;
        pen.setWidth(2);

        if(s == 0)
            pen.setColor(Qt::red);
        if(s == 1)
            pen.setColor(Qt::green);

        X = vizinhos[i]->getX();
        Y = vizinhos[i]->getY();
        QLineF line(x, y+40, X+80, Y+40);
        p->setPen(pen);
        p->drawLine(line);
    }
}

void Porta::atualiza()
{}
