#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "Sinal.h"

class Integrador{
private:
    Sinal* sinalOUT;

public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);


};


#endif