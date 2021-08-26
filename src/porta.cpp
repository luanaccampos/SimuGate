#include "porta.h"

Porta::Porta(int x, int y, QWidget *parent) : QLabel(parent)
{
    this->x = x;
    this->y = y;
    this->parent = parent;
    setVisible(true);
    connect(this, SIGNAL(clicked(int)), parent, SLOT(itwasclicked(int)));
    connect(this, SIGNAL(moved()), parent, SLOT(up()));
}

void Porta::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
    emit clicked(id);
}

void Porta::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
        this->move(mapToParent(event->pos() - offset));

    QPoint p = mapTo(parent, event->pos());

    x = p.x();
    y = p.y();

    emit moved();
}

void Porta::setId(int x)
{
    id = x;
}

void Porta::adcVizinho(int x)
{
    vizinhos.push_back(x);
}

int Porta::getX()
{
    return x;
}

int Porta::getY()
{
    return y;
}
