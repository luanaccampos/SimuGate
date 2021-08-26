#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <QGuiApplication>
#include <QScreen>
#include <QMenuBar>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>
#include "porta.h"
#include "and.h"
#include "or.h"
#include "true.h"
#include "false.h"
#include "grafo.h"

class janelaPrincipal : public QMainWindow
{
    Grafo g;
    int adc;
    QVector<int> click;
    Q_OBJECT
public:
    explicit janelaPrincipal(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
public slots:
    void adcAnd();
    void adcOr();
    void adcTrue();
    void adcFalse();
    void adcConexao();
    void itwasclicked(int id);
    void up();

};

#endif // JANELAPRINCIPAL_H
