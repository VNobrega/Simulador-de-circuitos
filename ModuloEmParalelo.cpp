#include "ModuloEmParalelo.h"
#include "Somador.h"
#include <stdexcept>

ModuloEmParalelo::ModuloEmParalelo():Modulo(){}
ModuloEmParalelo::~ModuloEmParalelo(){}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN){
    if(circuitos->size() == 0)
        throw new logic_error ("Modulo Vazio");
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    Somador* somador = new Somador();
    Sinal* sinalOUT = new Sinal(0.0, sinalIN->getComprimento());

    while(i != circuitos->end()) {
        sinalOUT = somador->processar(sinalOUT, (*i)->processar(sinalIN));
        i++;
    }

    somador->~Somador();
    
    return sinalOUT;
}
