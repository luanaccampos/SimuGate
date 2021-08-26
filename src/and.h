#ifndef AND_H
#define AND_H

#include "porta.h"

class And : public Porta
{
public:
    And(int x, int y, QWidget *parent);
    QString getTipo();
};

#endif // AND_H
