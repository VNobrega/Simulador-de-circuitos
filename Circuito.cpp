#include "Circuito.h"

int Circuito::ultimoID = 0;

Circuito::Circuito(){
    Circuito::ultimoID++;
    ID = Circuito::ultimoID;
}

Circuito::~Circuito(){}

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID [" << Circuito::ID << "]" << endl;
}

int Circuito::getUltimoID(){
    return Circuito::ultimoID;
}
