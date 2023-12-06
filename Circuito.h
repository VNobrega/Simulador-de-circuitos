#ifndef CIRCUITO_H
#define CIRCUITO_H

class Circuito{
private:

public:
Circuito();
virtual ~Circuito();
int getID();
void imprimir();
static int getUltimoID();

};

#endif
