#include "Somador.h"

Somador::Somador():CircuitoMISO(){}
Somador::~Somador(){};

Sinal* CircuitoMISO::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    int min = (sinalIN1->getComprimento()<sinalIN2->getComprimento())?sinalIN1->getComprimento():sinalIN2->getComprimento();
    double *sequencia = new double[min];

    for(int i=0; i<min; i++){
        sequencia[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
    }
    
    Sinal* sinalOUT = new Sinal(sequencia, min);
    delete[] sequencia;

    return sinalOUT;
}
