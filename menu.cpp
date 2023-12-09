#include <iostream>
#include <cmath>
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "PersistenciaDeModulo.h"

using namespace std;

Sinal* novoSinal();

CircuitoSISO* novaOperacao();

void menu(){
    int escolha;
    string nome;
    Modulo* moduloOUT;

    cout << "       Simulink em C++" << endl 
    << "Qual simulacao voce gostaria de fazer?" << endl
    << "1) Circuito advindo de arquivo" << endl
    << "2) Sua propria sequencia de operacoes" << endl
    << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1){
        Sinal* sinalIN = novoSinal();

        cout << "Qual o nome do arquivo a ser lido?" << endl
        << "Nome: ";
        cin >> nome;
        cout << endl;

        PersistenciaDeModulo* p = new PersistenciaDeModulo(nome);
        moduloOUT = p->lerDeArquivo();
        Sinal* sinalOUT = (moduloOUT)->processar(sinalIN);

        sinalOUT->imprimir("Resultado Final");

        p->~PersistenciaDeModulo();
        sinalIN->~Sinal();
        sinalOUT->~Sinal();
    }

    if(escolha == 2) {
        Sinal* sinalIN = novoSinal();
        cout << "Qual estrutura de operacoes voce deseja ter como base?" << endl
        << "1) Operacoes em serie nao realimentadas" << endl
        << "2) Operacoes em paralelo nao realimentadas" << endl
        << "3) Operacoes em serie realimentadas" << endl
        << "Escolha: " << endl;
        cin >> escolha;
        cout << endl;

        if(escolha == 1) moduloOUT = new ModuloEmSerie();
        if(escolha == 2) moduloOUT = new ModuloEmParalelo();
        if(escolha == 3) moduloOUT = new ModuloRealimentado();
        
        moduloOUT->adicionar(novaOperacao());
        moduloOUT->processar(sinalIN);
        sinalIN->imprimir("Resultado Final");
    }

    cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl
    << "1) Sim" << endl
    << "2) Nao" << endl
    << "Escolha: " << endl;
    cin >> escolha;
    cout << endl;

    if(escolha == 1) {
        cout << "Qual o nome do arquivo a ser escrito?" << endl
        << "Nome: ";
        cin >> nome;
        cout << endl;

        PersistenciaDeModulo* p = new PersistenciaDeModulo(nome);
        p->salvarEmArquivo(moduloOUT);
        p->~PersistenciaDeModulo();
    }
    moduloOUT->~Modulo();
    
}

Sinal* novoSinal(){
    double *sequencia = new double[60];
    int escolha;

    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
    << "1) 5+3*cos(n*pi/8)" << endl
    << "2) constante" << endl
    << "3) rampa" << endl
    << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1) {
        for(int i = 0; i < 60; i++)
            sequencia[i] = 5+3*cos(i*M_PI/8);
    }

    if(escolha == 2) {
        double c;

        cout << "Qual o valor dessa constante?" << endl
        << "C = ";
        cin >> c;
        cout << endl;

        for(int i = 0; i < 60; i++)
            sequencia[i] = c;
    }

    if(escolha == 3) {
        double a;

        cout << "Qual a inclinacao dessa rampa?" << endl
        << "a = ";
        cin >> a;
        cout << endl;

        for(int i = 0; i < 60; i++)
            sequencia[i] = i*a;
    }
    Sinal* sinalOUT = new Sinal(sequencia,60);
    delete[] sequencia;
    return sinalOUT;
}

CircuitoSISO* novaOperacao(){
    int escolha1,escolha2;

    cout << "Qual operacao voce gostaria de fazer?" << endl
    << "1) Amplificar" << endl
    << "2) Derivar" << endl
    << "3) Integrar" << endl
    << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    if(escolha1 == 1) {
        double g;

        cout << "Qual o ganho dessa amplificacao?" << endl
        << "g: ";
        cin >> g;
        cout << endl;

        Amplificador* circuito = new Amplificador(g);
        return circuito;
    }
    
    if(escolha1 == 2) {
        Derivador* circuito = new Derivador();
        return circuito;
    }

    if(escolha1 == 3) {
        Integrador* circuito = new Integrador();
        return circuito;
    }

    return nullptr;
    /*cout << "O que voce quer fazer agora?" << endl
    << "1) Realizar mais uma operacao no resultado" << endl
    << "2) Imprimir o resultado" << endl
    << "Escolha: ";
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1)
        novaOperacao(sinalIN);
    if(escolha2==2)
        sinalIN->imprimir("Resultado Final");
        sinalIN->~Sinal();*/
}