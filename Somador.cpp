#include "Somador.h"

Somador::Somador(){}

Somador::~Somador(){};

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    int min = (sinalIN1->getComprimento()<sinalIN2->getComprimento())?sinalIN1->getComprimento():sinalIN2->getComprimento();
    double sequencia[min];

    for(int i=0; i<min; i++){
        sequencia[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
    }
    
    sinalOUT = new Sinal(sequencia, min);
    return sinalOUT;
}