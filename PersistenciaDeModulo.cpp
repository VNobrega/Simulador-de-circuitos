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

    ModuloEmSerie* ms = dynamic_cast<ModuloEmSerie*>(mod);
    if(ms != NULL)
        output << "S" << endl;

    ModuloEmParalelo* mp = dynamic_cast<ModuloEmParalelo*>(mod);
    if(mp != NULL)
        output << "P" << endl;
        
    ModuloRealimentado* mr = dynamic_cast<ModuloRealimentado*>(mod);
    if(mr != NULL)
        output << "R" << endl;

    while(i != circuitos->end()) {
        ModuloEmSerie* s = dynamic_cast<ModuloEmSerie*>(*i);
        if(s != NULL)
            saidaArquivo(s,output);

        ModuloEmParalelo* p = dynamic_cast<ModuloEmParalelo*>(*i);
        if(p != NULL)
            saidaArquivo(p,output);

        ModuloRealimentado* r = dynamic_cast<ModuloRealimentado*>(*i);
        if(r != NULL)
            saidaArquivo(r,output);

        Amplificador* a = dynamic_cast<Amplificador*>(*i);
        if(a != NULL)
            output << "A " << a->getGanho() << endl;

        Integrador* g = dynamic_cast<Integrador*>(*i);
        if(g != NULL)
            output << "I" << endl;

        Derivador* d = dynamic_cast<Derivador*>(*i);
        if(d != NULL)
            output << "D" << endl;

        i++;
    }
    output << "f" << endl;

    delete circuitos;
}
    output << "f" << endl;

    delete circuitos;
}

Modulo* entradaArquivo(ifstream& input){

}
