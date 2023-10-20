#include "Sinal.h"

Sinal::Sinal(double *sequencia, int comprimento): comprimento(comprimento){
    this->sequencia = new double[comprimento];
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
    Grafico *g = new Grafico(nomeDoSinal, sequencia, comprimento);
    g->plot();
    g->~Grafico();
    
}

Sinal::~Sinal(){
    delete[] sequencia;
}