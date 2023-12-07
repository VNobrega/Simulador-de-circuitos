#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"

class ModuloEmParalelo:public Modulo{
private:
    list<CircuitoSISO*>* circuitos;
    
public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal* processar(Sinal* sinalIN);

};

#endif
