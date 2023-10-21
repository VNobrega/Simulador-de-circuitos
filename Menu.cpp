#include <iostream>
#include <cmath>
#include "Sinal.h"
#include "ModuloRealimentado.h"
#define MAX 60
#define PI 3.14159265359

using namespace std;

Sinal* novoSinal();

void menu(){
    int escolha1,escolha2;
    double c,g;

    cout << "       Simulink em C++" << endl 
    << "Qual simulacao voce gostaria de fazer?" << endl
    << "1) Piloto Automatico" << endl
    << "2) Sua propria sequencia de operacoes" << endl
    << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    if(escolha1 == 1){
        Sinal* sinal = novoSinal();

        cout << "Qual o ganho do acelerador?" << endl
        << "g = ";
        cin >> g;
        cout << endl;

        ModuloRealimentado* pilotoAutomatico = new ModuloRealimentado(g);
        (pilotoAutomatico->processar(sinal))->imprimir("Velocidade do Carro");
    }

    if(escolha1 == 2) {

    }
}

Sinal* novoSinal(){
    double sequencia[MAX];
    int escolha2;
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
    << "1) 5+3*cos(n*pi/8)" << endl
    << "2) constante" << endl
    << "3) rampa" << endl
    << "Escolha: ";
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1) {
        for(int i = 0; i < MAX; i++)
            sequencia[i] = 5+3*cos(i*PI/8);
    }

    if(escolha2 == 2) {
        double c;
        cout << "Qual o valor dessa constante?" << endl
        << "C = ";
        cin >> c;
        cout << endl;

        for(int i = 0; i < MAX; i++)
            sequencia[i] = c;
    }

    if(escolha2 == 3) {
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl
        << "a = ";
        cin >> a;
        cout << endl;

        for(int i = 0; i < MAX; i++)
            sequencia[i] = i*a;
    }
    Sinal* sinal = new Sinal(sequencia,MAX);
    return sinal;
}
