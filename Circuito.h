#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>
#include<string>
using namespace std;

class Circuito{
private:
    static int ultimoID;
    int ID;

public:
    Circuito();
    virtual ~Circuito() = 0;
    int getID();
    void imprimir();
    static int getUltimoID();

};

#endif
