#ifndef BANCADA_H
#define BANCADA_H

#include "RFIDReader.h"
#include "Processo.h"

// Classe que representa uma bancada de produção
class Bancada {
private:
    RFIDReader rfidReader;
    Processo* processoAtual;

public:
    Bancada(int ssPin, int rstPin, Processo* processo);
    void init();
    void executar();
};

#endif
