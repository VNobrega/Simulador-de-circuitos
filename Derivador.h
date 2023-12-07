#ifndef DERIVADOR_H
#define DERIVADOR_H

#include "CircuitoSISO.h"

class Derivador:public CircuitoSISO{
private:

public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);

};


#endif
