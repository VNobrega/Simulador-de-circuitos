#include "Derivador.h"

Derivador::Derivador(){}

Derivador::~Derivador(){}

Sinal* Derivador::processar(Sinal* sinalIN){
    int comprimento = sinalIN->getComprimento();
    double sequencia[comprimento];
    sequencia[0] = 0;
    for(int i=1; i<comprimento; i++){
        sequencia[i] = sinalIN->getSequencia()[i]-sinalIN->getSequencia()[i-1];
    }

   this->sinalOUT = new Sinal(sequencia, comprimento);

   return sinalOUT;

}

