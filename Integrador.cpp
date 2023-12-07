#include "Integrador.h"

Integrador::Integrador(): CircuitoSISO(){}
Integrador::~Integrador(){}

Sinal* Integrador::processar(Sinal* sinalIN){
    int comprimento = sinalIN->getComprimento();
    double *sequencia = new double[comprimento];

    sequencia[0] = sinalIN->getSequencia()[0];
    for(int i=1; i<comprimento; i++){
        sequencia[i] = sinalIN->getSequencia()[i]+sequencia[i-1];
    }

    Sinal* sinalOUT = new Sinal(sequencia, comprimento);
    delete[] sequencia;

    return sinalOUT;

}
