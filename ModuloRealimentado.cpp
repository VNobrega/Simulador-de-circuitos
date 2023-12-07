#include "ModuloRealimentado.h"
#include "Somador.h"

ModuloRealimentado::ModuloRealimentado(): Modulo(){
    ModuloEmSerie *moduloemserie = new ModuloEmSerie();
}

ModuloRealimentado::~ModuloRealimentado(){
    delete moduloemserie;
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){

    Somador *somador = new Somador();
    Sinal *diferenca = nullptr;
    Sinal *sinalOUT = nullptr;
    Sinal *saidaInvertida = nullptr;
    int comprimento = sinalIN->getComprimento();
    double *sequenciaSaidaInvertida = new double[comprimento];
    double vInicial = 0;


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

void ModuloRealimentado::adicionar(CircuitoSISO* circ){
    moduloemserie->adicionar(circ);
}

list<CircuitoSISO*>* ModuloRealimentado::getCircuitos(){
    return moduloemserie->getCircuitos();
}
