#include "Sinal.h"

Sinal::Sinal(double *sequencia, int comprimento): comprimento(comprimento){
    if(comprimento <= 0)
        throw new invalid_argument ("Comprimento Invalido");
    this->sequencia = new double[comprimento];
    for(int i = 0; i < comprimento; i++)
        this->sequencia[i] = sequencia[i];
}

Sinal::Sinal(double constante, int comprimento): comprimento(comprimento){
    if(comprimento <= 0)
        throw new invalid_argument ("Comprimento Invalido");
    sequencia = new double[comprimento];
    for(int i = 0; i < comprimento; i++)
        sequencia[i] = constante;
}

Sinal::~Sinal(){
    delete[] sequencia;
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

void Sinal::imprimir(){
    for(int i = 0; i < comprimento; i++)
        cout << i << "- " << sequencia[i] << endl;
    cout << "--" << endl;
}

void Sinal::imprimir(int tamanho){
    for(int i = 0; i < comprimento && i < tamanho; i++)
        cout << i << "- " << sequencia[i] << endl;
    cout << "--" << endl;
}
