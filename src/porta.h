#ifndef PORTA_H
#define PORTA_H

#include <QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QPainter>
#include <QDebug>

class Porta : public QLabel
{
    Q_OBJECT
    QWidget *parent;
protected:
    QVector <Porta *> vizinhos;
    QPoint offset;
    int saida, id, x, y;
public:
    Porta(int x, int y, int id, QWidget *parent);
    virtual QString getTipo() = 0;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    int getId();
    void removeVizinho(Porta *x);
    int getX();
    int getY();
    int getSaida();
    QVector<Porta *> getVizinhos();
    void drawArestas(QPainter *p);
    virtual void adcVizinho(Porta *x);
    virtual void atualiza();
    virtual void selected() = 0;
    virtual void unSelected() = 0;
signals:
    void clicked(int id);
    void moved();
};

#endif // PORTA_H
