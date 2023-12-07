#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"

class ModuloRealimentado:public Modulo{
private:
    ModuloEmSerie* moduloemserie;
    
public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();

};

#endif
