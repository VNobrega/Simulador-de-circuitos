#include "ModuloRealimentado.h"
#include "Piloto.h"
#include "Somador.h"


ModuloRealimentado::ModuloRealimentado(double ganho):ganho(ganho){}

ModuloRealimentado::~ModuloRealimentado(){}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
   
    Piloto *piloto = new Piloto(ganho);
    Somador *somador = new Somador();
    Sinal *diferenca = nullptr;
    Sinal *sinalOUT = nullptr;
    Sinal *saidaInvertida = nullptr;
    int comprimento = sinalIN->getComprimento();
    double *sequenciaSaidaInvertida = new double[comprimento];
    double vInicial = 0;


    sequenciaSaidaInvertida[0] = 0;
    diferenca = new Sinal(sinalIN->getSequencia(),1);
    sinalOUT = piloto->processar(diferenca);
    diferenca->~Sinal();

   

    for(int i=1; i<comprimento; i++){
        sequenciaSaidaInvertida[i] = -sinalOUT->getSequencia()[i-1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1);
        diferenca = somador->processar(sinalIN, saidaInvertida);
        sinalOUT->~Sinal();
        sinalOUT = piloto->processar(diferenca);
        saidaInvertida->~Sinal();
        diferenca->~Sinal();

    }

    delete[] sequenciaSaidaInvertida;
    piloto->~Piloto();
    somador->~Somador();

    return sinalOUT;

}