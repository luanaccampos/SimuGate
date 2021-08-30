#ifndef FALSE_H
#define FALSE_H

#include "porta.h"

class False : public Porta
{
public:
    False(int x, int y, int id, QWidget *parent);
    QString getTipo();
    void selected();
    void unSelected();
    void adcVizinho(Porta *x);
};

#endif // FALSE_H
