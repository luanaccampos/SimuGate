#ifndef OR_H
#define OR_H

#include "porta.h"

class Or : public Porta
{
public:
    Or(int x, int y, int id, QWidget *parent);
    QString getTipo();
    void selected();
    void unSelected();
    void atualiza();
};

#endif // OR_H
