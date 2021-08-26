#include "janelaprincipal.h"

janelaPrincipal::janelaPrincipal(QWidget *parent) : QMainWindow(parent)
{
    QScreen *q = QGuiApplication::primaryScreen();
    resize(q->availableSize());
    setWindowTitle("SimuGate");

    adc = -1;

    QMenuBar *barra = new QMenuBar(this);
    QMenu *arquivo = new QMenu("Arquivo", this);
    QMenu *adc = new QMenu("Adicionar", this);
    QAction *novo = new QAction("Novo", this);
    QAction *abrir = new QAction("Abrir", this);
    QAction *salvar = new QAction("Salvar", this);
    QAction *adcAnd = new QAction("AND", this);
    QAction *adcOr = new QAction("OR", this);
    QAction *adcTrue = new QAction("TRUE", this);
    QAction *adcFalse = new QAction("FALSE", this);
    QAction *adcConexao = new QAction("CONEXÃO", this);

    adc->addAction(adcTrue);
    adc->addAction(adcFalse);
    adc->addSeparator();
    adc->addAction(adcAnd);
    adc->addAction(adcOr);
    adc->addSeparator();
    adc->addAction(adcConexao);

    arquivo->addAction(novo);
    arquivo->addAction(abrir);
    arquivo->addAction(salvar);

    connect(adcAnd, SIGNAL(triggered()), this, SLOT(adcAnd()));
    connect(adcOr, SIGNAL(triggered()), this, SLOT(adcOr()));
    connect(adcTrue, SIGNAL(triggered()), this, SLOT(adcTrue()));
    connect(adcFalse, SIGNAL(triggered()), this, SLOT(adcFalse()));
    connect(adcConexao, SIGNAL(triggered()), this, SLOT(adcConexao()));

    barra->setGeometry(0, 0, q->availableSize().width(), 25);
    barra->addMenu(arquivo);
    barra->addMenu(adc);
}

void janelaPrincipal::mousePressEvent(QMouseEvent *event)
{
    click.clear();
    int x, y;
    x = event->x();
    y = event->y();

    if(adc == 0)
        g += new And(x, y, this);
    if(adc == 1)
        g += new Or(x, y, this);
    if(adc == 2)
        g += new True(x, y, this);
    if(adc == 3)
        g += new False(x, y, this);

    adc = -1;
}

void janelaPrincipal::paintEvent(QPaintEvent *event)
{
    QPainter *p = new QPainter(this);
    g.drawArestas(p);

    delete p;
}

void janelaPrincipal::adcAnd()
{
    adc = 0;
}

void janelaPrincipal::adcOr()
{
    adc = 1;
}

void janelaPrincipal::adcTrue()
{
    adc = 2;
}

void janelaPrincipal::adcFalse()
{
    adc = 3;
}

void janelaPrincipal::adcConexao()
{
    adc = 4;
}

void janelaPrincipal::itwasclicked(int id)
{
    if(adc == 4)
    {
        if(click.count(id) == 0)
            click.push_back(id);

        if(click.size() == 2)
        {
            g.addAresta(click[0], click[1]);
            click.clear();
            adc = -1;
            update();
        }
    }
}

void janelaPrincipal::up()
{
    update();
}




