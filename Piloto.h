#ifndef PILOTO_H
#define PILOTO_H

#include "Sinal.h"

class Piloto{
private:
    

public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

};



#endif