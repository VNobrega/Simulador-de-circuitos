#include "ModuloEmSerie.h"
#include <stdexcept>

ModuloEmSerie::ModuloEmSerie():Modulo(){}
ModuloEmSerie::~ModuloEmSerie(){}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN){
    if(circuitos->size() == 0)
        throw new logic_error ("Modulo Vazio");
    list<CircuitoSISO*>::iterator i = circuitos->begin();
    Sinal* sinalOUT = sinalIN;

    while(i != circuitos->end()) {
        sinalOUT = (*i)->processar(sinalOUT);
        i++;
    }
    
    return sinalOUT;
}
