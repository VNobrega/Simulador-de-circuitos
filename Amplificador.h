#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"

class Amplificador:public CircuitoSISO{
private:
    double ganho;

public:
    Amplificador(double ganho); 
    virtual ~Amplificador();
    void setGanho(double ganho); 
    double getGanho();
    Sinal* processar(Sinal* sinalIN);

};

#endif
