#ifndef MODULOEMSERIE_H
#define MODULOEMSERIE_H

#include "Modulo.h"

class ModuloEmSerie:public Modulo{
private:
    list<CircuitoSISO*>* circuitos;
    
public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    Sinal* processar(Sinal* sinalIN);

};

#endif
