#ifndef CONTROLELINHADEPRODUCAO_H
#define CONTROLELINHADEPRODUCAO_H

#include "Bancada.h"

// Classe que controla a sequência de bancadas em uma linha de produção
class ControleLinhaDeProducao {
private:
    Bancada* bancadas[5];

public:
    ControleLinhaDeProducao(Bancada* b1, Bancada* b2, Bancada* b3, Bancada* b4, Bancada* b5);
    void iniciarProducao();
};

#endif
