#include "Modulo.h"
#include "Integrador.h"

Modulo::Modulo():CircuitoSISO(){
    this->circuitos = new list<CircuitoSISO*>();
}

Modulo::~Modulo(){
    delete circuitos;
}

void Modulo::adicionar(CircuitoSISO* circ){
    circuitos->push_back(circ);
}

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return circuitos;
}

void Modulo::imprimir(){
    list<CircuitoSISO*>::iterator i = circuitos->begin();

    cout << "Modulo com ID [" << getID() << "] e:" << endl;
    while(i != circuitos->end()) {
        cout << "Circuito com ID [" << (*i)->getID() << "]" << endl;
        i++;
    }
    cout << "--" << endl;
}
