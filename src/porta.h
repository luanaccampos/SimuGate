#ifndef PORTA_H
#define PORTA_H

#include <QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>

class Porta : public QLabel
{
    Q_OBJECT
    QWidget *parent;
    int id, x, y;
public:
    Porta(int x, int y, QWidget *parent);
    virtual QString getTipo() = 0;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setId(int x);
    void adcVizinho(int x);
    int getX();
    int getY();
    QVector <int> vizinhos;
protected:
    QPoint offset;
signals:
    void clicked(int id);
    void moved();
};

#endif // PORTA_H
