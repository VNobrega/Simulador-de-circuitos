#include "Amplificador.h"

Amplificador::Amplificador(double ganho): ganho(ganho){

}

Sinal* Amplificador::processar(Sinal* sinalIN){
    for(int i=0; i<sinalIN->getComprimento(); i++){
        sinalIN[i] *= ganho;
    }
    return sinalIN;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return ganho;
}
