#include "ModuloRealimentado.h"
#include "Somador.h"

ModuloRealimentado::ModuloRealimentado(): Modulo(){
    this->moduloemserie = new ModuloEmSerie();
}

ModuloRealimentado::~ModuloRealimentado(){
    moduloemserie->~Modulo();
}

void ModuloRealimentado::adicionar(CircuitoSISO* circ){
    moduloemserie->adicionar(circ);
}

list<CircuitoSISO*>* ModuloRealimentado::getCircuitos(){
    return moduloemserie->getCircuitos();
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
    Somador *somador = new Somador();
    Sinal *diferenca = nullptr;
    Sinal *sinalOUT = nullptr;
    Sinal *saidaInvertida = nullptr;
    int comprimento = sinalIN->getComprimento();
    double *sequenciaSaidaInvertida = new double[comprimento];
    sequenciaSaidaInvertida[0] = 0;
    diferenca = new Sinal(sinalIN->getSequencia(),1);
    
    sinalOUT = moduloemserie->processar(diferenca);
    
    diferenca->~Sinal();

    for(int i=1; i<comprimento; i++){
        sequenciaSaidaInvertida[i] = -sinalOUT->getSequencia()[i-1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1);
        diferenca = somador->processar(sinalIN, saidaInvertida);
        sinalOUT->~Sinal();
        sinalOUT = moduloemserie->processar(diferenca);
        saidaInvertida->~Sinal();
        diferenca->~Sinal();

    }

    delete[] sequenciaSaidaInvertida;
    somador->~Somador();

    return sinalOUT;
}
