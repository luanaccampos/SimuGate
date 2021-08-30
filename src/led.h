#ifndef LED_H
#define LED_H

#include "porta.h"

class Led : public Porta
{
public:
    Led(int x, int y, int id, QWidget *parent);
    QString getTipo();
    void selected();
    void unSelected();
    void atualiza();
    void adcVizinho(Porta *x);
};

#endif // LED_H
