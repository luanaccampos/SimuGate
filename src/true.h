#ifndef TRUE_H
#define TRUE_H

#include "porta.h"

class True : public Porta
{
public:
    True(int x, int y, int id, QWidget *parent);
    QString getTipo();
    void selected();
    void unSelected();
    void adcVizinho(Porta *x);
};

#endif // TRUE_H
