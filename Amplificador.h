#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"

class Amplificador:public CircuitoSISO{
private:

public:
    Amplificador(double ganho); 
    virtual ~Amplificador();
    void setGanho(double ganho); 
    double getGanho();

};



#endif
