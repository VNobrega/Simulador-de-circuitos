#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "CircuitoSISO.h"

class Integrador:public CircuitoSISO{
private:

public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);

};


#endif
