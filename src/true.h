#ifndef TRUE_H
#define TRUE_H

#include "porta.h"

class True : public Porta
{
public:
    True(int x, int y, QWidget *parent);
    QString getTipo();
};

#endif // TRUE_H
