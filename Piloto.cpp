#include "Piloto.h"
#include "Amplificador.h"
#include "Integrador.h"

Piloto::Piloto(double ganho):ganho(ganho){}

Piloto::~Piloto(){}

Sinal* Piloto::processar(Sinal* sinalIN){
    int tamanho = sinalIN->getComprimento();
    Amplificador *amplificador = new Amplificador(ganho);
    Integrador *integrador = new Integrador();

    Sinal* sequencia = amplificador->processar(sinalIN);
    sinalOUT = integrador->processar(sequencia);
    
    amplificador->~Amplificador();
    integrador->~Integrador();
    sequencia->~Sinal();

    return sinalOUT;

}