#include "janelaprincipal.h"

janelaPrincipal::janelaPrincipal(QWidget *parent) : QMainWindow(parent)
{
    QScreen *q = QGuiApplication::primaryScreen();
    resize(q->availableSize());
    setWindowTitle("SimuGate");
    setStyleSheet("QWidget{background-color: #282a36; color: #f8f8f2;}"
    "QMenuBar{background-color: #44475a; color: #f8f8f2; spacing: 10px;}"
    "QMenuBar::item:selected{background: #bd93f9;}"
    "QMenu{background: #44475a; color: #f8f8f2;}"
    "QMenu::item:selected{background: #bd93f9;}");

    seed = 0;
    adc = select = -1;

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
    QAction *adcLed = new QAction("LED", this);
    QAction *apaga = new QAction(this);

    adc->addAction(adcTrue);
    adc->addAction(adcFalse);
    adc->addAction(adcLed);
    adc->addSeparator();
    adc->addAction(adcAnd);
    adc->addAction(adcOr);
    adc->addSeparator();
    adc->addAction(adcConexao);

    arquivo->addAction(novo);
    arquivo->addAction(abrir);
    arquivo->addAction(salvar);

    novo->setShortcut(tr("Ctrl+N"));
    abrir->setShortcut(tr("Ctrl+A"));
    salvar->setShortcut(tr("Ctrl+S"));
    adcTrue->setShortcut(tr("T"));
    adcFalse->setShortcut(tr("F"));
    adcLed->setShortcut(tr("L"));
    adcAnd->setShortcut(tr("A"));
    adcOr->setShortcut(tr("O"));
    adcConexao->setShortcut(tr("C"));

    apaga->setShortcut(QKeySequence::Delete);
    addAction(apaga);

    connect(adcAnd, SIGNAL(triggered()), this, SLOT(adcAnd()));
    connect(adcOr, SIGNAL(triggered()), this, SLOT(adcOr()));
    connect(adcTrue, SIGNAL(triggered()), this, SLOT(adcTrue()));
    connect(adcFalse, SIGNAL(triggered()), this, SLOT(adcFalse()));
    connect(adcConexao, SIGNAL(triggered()), this, SLOT(adcConexao()));
    connect(adcLed, SIGNAL(triggered()), this, SLOT(adcLed()));
    connect(apaga, SIGNAL(triggered()), this, SLOT(apaga()));
    connect(salvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(novo, SIGNAL(triggered()), this, SLOT(novo()));
    connect(abrir, SIGNAL(triggered()), this, SLOT(abrir()));

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

    Porta *novo = NULL;

    if(adc == 0)
        novo = new And(x, y, seed, this);
    if(adc == 1)
        novo = new Or(x, y, seed, this);
    if(adc == 2)
        novo = new True(x, y, seed, this);
    if(adc == 3)
        novo = new False(x, y, seed, this);
    if(adc == 5)
        novo = new Led(x, y, seed, this);

    if(novo != NULL)
    {
        g += novo;
        seed++;
    }

    adc = -1;

    if(select != -1)
    {
        g[select]->unSelected();
        select = -1;
    }
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

void janelaPrincipal::adcLed()
{
    adc = 5;
}

void janelaPrincipal::itwasclicked(int id)
{
    if(select != -1)
        g[select]->unSelected();

    select = id;
    g[id]->selected();

    if(adc == 4)
    {
        if(click.count(id) == 0)
            click.push_back(id);

        if(click.size() == 2)
        {
            try
            {
                g.addAresta(click[0], click[1]);
            }
            catch (int erro)
            {
                if(erro == 1)
                    QMessageBox::warning(this, "ERRO", "Essa porta não aceita entradas!");
                if(erro == 2)
                    QMessageBox::warning(this, "ERRO", "Essa porta aceita apenas uma entrada!");
                if(erro == 3)
                    QMessageBox::warning(this, "ERRO", "LED não deve ter saída!");
            }

            click.clear();
            adc = select = -1;
            g[id]->unSelected();
            update();
        }
    }
}

void janelaPrincipal::up()
{
    update();
}

void janelaPrincipal::apaga()
{
    if(select != -1)
    {
        g.apaga(select);
        select = -1;
        update();
    }
}

void janelaPrincipal::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this);
    QFile *arquivo = new QFile(nomeArquivo);

    if(!(*arquivo).open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "ERRO", "Não foi possível salvar o arquivo");
        return;
    }

    g.grafo2File(arquivo);
}

void janelaPrincipal::novo()
{
    g.clear();
    seed = 0;
    update();
}

void janelaPrincipal::abrir()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this);
    QFile arquivo(nomeArquivo);

    if(!arquivo.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "ERRO", "Não foi possível abrir o arquivo");
        return;
    }

    novo();

    QTextStream entrada(&arquivo);
    QString texto;
    QVector<QVector<int>> v;
    QVector<int> ids;

    while(!arquivo.atEnd())
    {
        texto = arquivo.readLine();
        QStringList list = texto.split(QString(" "));

        int id = list[1].toInt();
        int x = list[2].toInt();
        int y = list[3].toInt();
        int n = list[4].toInt();

        if(list[0] == "T")
            g += new True(x, y, id, this);
        if(list[0] == "F")
            g += new False(x, y, id, this);
        if(list[0] == "A")
            g += new And(x, y, id, this);
        if(list[0] == "O")
            g += new Or(x, y, id, this);
        if(list[0] == "L")
            g += new Led(x, y, id, this);

        int i = 5;

        QVector<int> viz;

        while(n--)
        {
            int u = list[i++].toInt();
            viz.push_back(u);
        }

        v.push_back(viz);
        ids.push_back(id);
        seed = std::max(seed, id);
    }

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
            g.addAresta(v[i][j], ids[i]);
    }

    seed++;
    g.atualiza();
    update();
}




