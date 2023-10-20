#include "Sinal.h"
int Sinal::max = 60;

Sinal::Sinal(double *sequencia, int comprimento): comprimento(comprimento){

    for(int i=0; i<comprimento; i++){
        this->sequencia[i] = sequencia[i];
    }

}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){

    //implementar
}