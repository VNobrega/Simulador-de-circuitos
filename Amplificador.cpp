#include "Amplificador.h"

Amplificador::Amplificador(double ganho): CircuitoSISO(){
    this->ganho = ganho;
}

Amplificador::~Amplificador(){}

Sinal* CircuitoSISO::processar(Sinal* sinalIN){
    int comprimento = sinalIN->getComprimento();
    double *sequencia = new double[comprimento];

    for(int i = 0; i < comprimento; i++){
        sequencia[i] = sinalIN->getSequencia()[i] * ganho;
    }
    Sinal *sinalA = new Sinal(sequencia,comprimento);
    delete[] sequencia;
    
    return sinalA;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return ganho;
}
