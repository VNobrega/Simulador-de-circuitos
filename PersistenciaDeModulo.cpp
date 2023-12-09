#include "PersistenciaDeModulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include <stdexcept>

char c;

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


void saidaArquivo(Modulo* mod,ofstream& output){
    list<CircuitoSISO*>* circuitos = new list<CircuitoSISO*>;

    ModuloEmSerie* ms = dynamic_cast<ModuloEmSerie*>(mod);
    if(ms != NULL){
        output << "S" << endl;
        circuitos = ms->getCircuitos();
    }

    ModuloEmParalelo* mp = dynamic_cast<ModuloEmParalelo*>(mod);
    if(mp != NULL){
        output << "P" << endl;
        circuitos = mp->getCircuitos();
    }

    ModuloRealimentado* mr = dynamic_cast<ModuloRealimentado*>(mod);
    if(mr != NULL){
        output << "R" << endl;
        circuitos = mr->getCircuitos();
    }

    list<CircuitoSISO*>::iterator i = circuitos->begin();

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

}

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream input;
    input.open(nomeDoArquivo);

    if(input.fail()) {
        input.close();
        throw new invalid_argument ("Arquivo nao encontrado");
    }

    input>>c;
    Modulo* moduloLido = entradaArquivo(input);
    
    if(!input.eof()){
        input.close();
        moduloLido->~Modulo();
        throw new logic_error ("Erro de leitura");
    }
    
    input.close();

    return moduloLido;
}

Modulo* entradaArquivo(ifstream& input){
    Modulo* moduloLer = nullptr;
    if(c == 'S') moduloLer = new ModuloEmSerie();
    if(c == 'P') moduloLer = new ModuloEmParalelo();
    if(c == 'R') moduloLer = new ModuloRealimentado();
    input>>c;

    while(c != 'f'){
        if(c == 'S' || c == 'P' || c == 'R') moduloLer->adicionar(entradaArquivo(input));
        else if(c == 'I'){
            CircuitoSISO *circ = new Integrador();
            moduloLer->adicionar(circ);
            input>>c;
        }
        else if(c == 'D'){
            CircuitoSISO *circ = new Derivador();
            moduloLer->adicionar(circ);
            input>>c;
        }
        else if(c == 'A'){
            double d;
            if(!(input>>d)) return moduloLer;
            CircuitoSISO *circ = new Amplificador(d);
            moduloLer->adicionar(circ);
            input>>c;
        } 
        else return moduloLer;
        
    }

    input>>c;
    return moduloLer; 

}