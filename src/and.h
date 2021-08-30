#ifndef AND_H
#define AND_H

#include "porta.h"

class And : public Porta
{
public:
    And(int x, int y, int id, QWidget *parent);
    QString getTipo();
    void selected();
    void unSelected();
    void atualiza();
};

#endif // AND_H
