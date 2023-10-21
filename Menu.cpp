#include <iostream>
#include <cmath>
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#define MAX 60
#define PI 3.14159265359

using namespace std;

Sinal* novoSinal();

void novaOperacao(Sinal *sinalIN);

void menu(){
    int escolha;

    cout << "       Simulink em C++" << endl 
    << "Qual simulacao voce gostaria de fazer?" << endl
    << "1) Piloto Automatico" << endl
    << "2) Sua propria sequencia de operacoes" << endl
    << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1){
        double g;
        Sinal* sinalIN = novoSinal();

        cout << "Qual o ganho do acelerador?" << endl
        << "g = ";
        cin >> g;
        cout << endl;

        ModuloRealimentado* pilotoAutomatico = new ModuloRealimentado(g);
        (pilotoAutomatico->processar(sinalIN))->imprimir("Velocidade do Carro");
    }

    if(escolha == 2) {
        Sinal* sinalIN = novoSinal();
        novaOperacao(sinalIN);
    }
}

Sinal* novoSinal(){
    double sequencia[MAX];
    int escolha;

    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
    << "1) 5+3*cos(n*pi/8)" << endl
    << "2) constante" << endl
    << "3) rampa" << endl
    << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1) {
        for(int i = 0; i < MAX; i++)
            sequencia[i] = 5+3*cos(i*PI/8);
    }

    if(escolha == 2) {
        double c;

        cout << "Qual o valor dessa constante?" << endl
        << "C = ";
        cin >> c;
        cout << endl;

        for(int i = 0; i < MAX; i++)
            sequencia[i] = c;
    }

    if(escolha == 3) {
        double a;

        cout << "Qual a inclinacao dessa rampa?" << endl
        << "a = ";
        cin >> a;
        cout << endl;

        for(int i = 0; i < MAX; i++)
            sequencia[i] = i*a;
    }
    Sinal* sinalOUT = new Sinal(sequencia,MAX);
    return sinalOUT;
}

void novaOperacao(Sinal *sinalIN){
    int escolha1,escolha2;

    cout << "Qual operacao voce gostaria de fazer?" << endl
    << "1) Amplificar" << endl
    << "2) Somar" << endl
    << "3) Derivar" << endl
    << "4) Integrar" << endl
    << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    if(escolha1 == 1) {
        double g;

        cout << "Qual o ganho dessa amplificacao?" << endl
        << "g: ";
        cin >> g;
        cout << endl;

        Amplificador* amplificador = new Amplificador(g);
        sinalIN = amplificador->processar(sinalIN);
    }
    
    if(escolha1 == 2) {
        cout << "Informe mais um sinal para ser somado." << endl << endl;

        Sinal* sinalIN2 = novoSinal();
        Somador* somador = new Somador();
        sinalIN = somador->processar(sinalIN, sinalIN2);
    }

    cout << "O que voce quer fazer agora?" << endl
    << "1) Realizar mais uma operacao no resultado" << endl
    << "2) Imprimir o resultado para terminar" << endl
    << "Escolha: ";
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1)
        novaOperacao(sinalIN);
    if(escolha2==2)
        sinalIN->imprimir("Resultado Final");
}
