#ifndef OR_H
#define OR_H

#include "porta.h"

class Or : public Porta
{
public:
    Or(int x, int y, QWidget *parent);
    QString getTipo();
};

#endif // OR_H
