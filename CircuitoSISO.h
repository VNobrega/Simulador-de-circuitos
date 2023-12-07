#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Circuito.h"
#include "Sinal.h"

class CircuitoSISO: public Circuito{
private:

protected:
    double ganho;

public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* sinalIN) = 0;

};

#endif
