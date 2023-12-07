#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include <fstream>

class PersistenciaDeModulo{
private:
    string nomeDoArquivo;

public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();

};

#endif
