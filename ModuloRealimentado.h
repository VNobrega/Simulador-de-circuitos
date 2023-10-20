#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"

class ModuloRealimentado{
private:
    

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);

};



#endif