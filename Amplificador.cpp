#include "Amplificador.h"

Amplificador::Amplificador(double ganho): ganho(ganho){

}

Sinal* Amplificador::processar(Sinal* sinalIN){
    int comprimento = sinalIN->getComprimento();
    double *sequencia[comprimento];
    Sinal sinalA = new Sinal(sequencia,comprimento);
    for(int i = 0; i < comprimento; i++){
        sinalA[i] = sinalIN[i] * ganho;
    }
    return sinalA;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return ganho;
}
