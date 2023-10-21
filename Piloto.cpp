#include "Piloto.h"
#include "Amplificador.h"
#include "Integrador.h"

Piloto::Piloto(double ganho):ganho(ganho){}

Piloto::~Piloto(){}

Sinal* Piloto::processar(Sinal* sinalIN){
    int tamanho = sinalIN->getComprimento();
    Amplificador *amplificador = new Amplificador(ganho);
    Integrador *integrador = new Integrador();

    sinalOUT = amplificador->processar(sinalIN);
    sinalOUT = integrador->processar(sinalOUT);
    
    amplificador->~Amplificador();
    integrador->~Integrador();

    return sinalOUT;

}