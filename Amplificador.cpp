#include "Amplificador.h"

Amplificador::Amplificador(double ganho): ganho(ganho){

}

Sinal* Amplificador::processar(Sinal* sinalIN){
    int comprimento = sinalIN->getComprimento();
    double *sequencia[comprimento];
    double *sequenciaIN[comprimento] = sinalIN->getSequencia();
    for(int i = 0; i < comprimento; i++){
        sequencia[i] = sequenciaIN[i] * ganho;
    }
    Sinal sinalA = new Sinal(sequencia,comprimento);
    return sinalA;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return ganho;
}
