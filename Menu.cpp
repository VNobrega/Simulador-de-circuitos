#include <iostream>

using namespace std;

void menu(){
    int escolha1,escolha2;
    double c,g;

    cout << "       Simulink em C++" << endl 
    << "Qual simulacao voce gostaria de fazer?" << endl
    << "1) Piloto Automatico" << endl
    << "2) Sua propria sequencia de operacoes" << endl
    << "Escolha: ";
    cin >> escolha1;
    cout << endl << endl

    << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
    << "1) 5+3*cos(n*pi/8)" << endl
    << "2) constante" << endl
    << "3) rampa" << endl
    << "Escolha: ";
    cin >> escolha2;
    cout << endl << endl

    << "Qual o valor dessa constante?" << endl
    << "C = ";
    cin >> c;
    cout << endl << endl

    << "Qual o ganho do acelerador?" << endl
    << "g = ";
    cin >> g;
    cout << endl;
}
