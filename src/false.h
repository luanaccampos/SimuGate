#ifndef FALSE_H
#define FALSE_H

#include "porta.h"

class False : public Porta
{
public:
    False(int x, int y, QWidget *parent);
    QString getTipo();
};

#endif // FALSE_H
