#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"

class ModuloRealimentado:public Modulo{
private:
    Modulo* moduloemserie;
    
public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
    virtual void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
    void imprimir();

};

#endif
