#include "PersistenciaDeModulo.h"

void saidaArquivo(Modulo* mod,ofstream& output);

Modulo* entradaArquivo(ifstream& input);

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo): nomeDoArquivo(nomeDoArquivo){}
PersistenciaDeModulo::~PersistenciaDeModulo(){}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod){
    ofstream output;
    output.open(nomeDoArquivo);

    saidaArquivo(mod,output);

    output.close();
}

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream input;
    input.open(nomeDoArquivo);

    if(input.fail()) {
        input.close();
        throw new invalid_argument ("Arquivo nao encontrado");
    }

    Modulo* moduloLido = entradaArquivo(input);

    if(!input.eof()){
        input.close();
        throw new logic_error ("Erro de leitura");
    }
    
    input.close();

    return moduloLido;
}

void saidaArquivo(Modulo* mod,ofstream& output){
    list<CircuitoSISO*>* circuitos = mod->getCircuitos();
    list<CircuitoSISO*>::iterator i = circuitos->begin();

    while(i != circuitos->end()) {
        ModuloEmSerie* s = dynamic_cast<ModuloEmSerie*>(*i);
        if(s != NULL){
            output << "S" << endl;
            saidaArquivo(s,output);
            delete s;
        }
        else delete s;
        ModuloEmParalelo* p = dynamic_cast<ModuloEmParalelo*>(*i);
        if(p != NULL){
            output << "P" << endl;
            saidaArquivo(p,output);
            delete p;
        }
        else delete p;
        ModuloRealimentado* r = dynamic_cast<ModuloRealimentado*>(*i);
        if(r != NULL){
            output << "R" << endl;
            saidaArquivo(r,output);
            delete r;
        }
        else delete r;
        Amplificador* a = dynamic_cast<Amplificador*>(*i);
        if(a != NULL){
            output << "A " << a->getGanho() << endl;
            delete a;
        }
        else delete a;
        Integrador* g = dynamic_cast<Integrador*>(*i);
        if(g != NULL){
            output << "I" << endl;
            delete g;
        }
        else delete g;
        Derivador* d = dynamic_cast<Derivador*>(*i);
        if(d != NULL){
            output << "D" << endl;
            delete d;
        }
        else delete d;

        i++;
    }
    output << "f" << endl;

    delete circuitos;
}

Modulo* entradaArquivo(ifstream& input){

}
